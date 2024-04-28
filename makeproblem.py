from selenium import webdriver
from selenium.webdriver.chrome.service import Service
from webdriver_manager.chrome import ChromeDriverManager
from selenium.webdriver.chrome.options import Options
from markdownify import markdownify
from icecream import ic
from bs4 import BeautifulSoup
import os
import argparse

# Chrome WebDriver 다운로드 및 관리
service = Service(ChromeDriverManager().install())

def get_driver_source(url):
    # Selenium 웹 드라이버 설정
    options = Options()
    # options.add_argument('--headless')  # 브라우저를 표시하지 않고 실행

    try:
        # Chrome WebDriver 시작
        driver = webdriver.Chrome(service=service, options=options)

        # 페이지 열기
        driver.get(url)

        # 페이지 소스 가져오기
        page_source = driver.page_source

        # 웹 드라이버 종료
        driver.quit()
    except:
        raise Exception()

    return page_source


def remake_html_source(page_source):
    # BeautifulSoup을 사용하여 HTML 파싱
    try:
        soup = BeautifulSoup(page_source, "html.parser")
    except:
        raise ValueError()

    # 지정된 CSS 선택자에 해당하는 내용 추출
    content = soup.select(
        "body > div.wrapper > div.container.content > div.row > div:nth-child(n+4):nth-child(-n+5)"
    )

    # 문제 제목 추출
    problem_title = soup.select_one("#problem_title").text.strip()

    # 문제 페이지 URL 추출
    problem_url = soup.select_one(
        "body > div.wrapper > div.container.content > div.row > div:nth-child(2) > ul > li.active > a"
    )["href"]
    number = problem_url.split("/")[-1]

    # h1 태그와 a 태그를 사용하여 하이퍼링크 생성
    html_code = f"<h1><a href='https://www.acmicpc.net{problem_url}'>{number}번 : {problem_title}</a></h1>"

    # 추출한 내용을 문자열로 변환하여 반환
    if content:
        return html_code + "\n".join(str(tag) for tag in content)
    else:
        return None


def replace_str(text):
    index = text.find("힌트")
    if index != -1:
        # "힌트" 이후의 문자열을 삭제
        new_text = text[:index]  # "힌트" 이후의 모든 문자열을 삭제
    else:
        new_text = text[:]
    new_text = new_text.replace(" 복사\n-----------\n\n\n\n\n```", "```css")
    new_text = new_text.replace("\n\n```", "\n```")
    new_text = new_text.replace("\n\n\n\n", "\n\n")
    new_text = new_text.replace("\n\n\n", "\n")
    new_text = new_text.replace("예제", "### 예제")
    return new_text


def make_markdown_file(filename, contents):
    # Markdown 파일 생성 및 내용 쓰기
    with open(filename, "w", encoding="utf-8") as file:
        file.write(contents + "\n\n")
    print(f"Markdown 파일 '{filename}'이 생성되었습니다.")


def convert_markdown(problem_number):
    assert isinstance(problem_number, str), "type of number is str."
    assert isinstance(int(problem_number), int), "type of problem_number is int."

    # 백준 문제 페이지 URL
    url = f"https://www.acmicpc.net/problem/{problem_number}"

    try:
        page_source = get_driver_source(url)
    except:
        try:
            page_source = get_driver_source(url)    
        except:
            raise ValueError()
    try:
        remaked_source = remake_html_source(page_source)
    except ValueError:
        ic(problem_number, "error remake_html_source")
        remaked_source = None

    if remaked_source is None:
        ic(problem_number)
        make_markdown_file(f"error_{problem_number}.txt", page_source)
        raise ValueError()
    markdown_text = markdownify(remaked_source)

    postprocess_text = replace_str(markdown_text)
    return postprocess_text


def main(problem_number, target_path="."):
    assert os.path.exists(target_path), f"'{target_path}'가 존재하지 않습니다."

    target_path = f"{target_path}/{problem_number}.md"

    # 파일이 빈 파일인지 확인
    if os.path.isfile(target_path):
        assert (
            not os.path.getsize(target_path) > 0
        ), f"'{target_path}'는(은) 비어있지 않은 파일입니다."

    postprocess_text = convert_markdown(problem_number)
    make_markdown_file(target_path, postprocess_text)


def parse_opt():
    parser = argparse.ArgumentParser(
        description="Convert Baekjoon problem list in README.md to Markdown format"
    )
    parser.add_argument(
        "--number",
        type=str,
        default="10808",
        help='Baekjoon question number ex)"10808"',
    )
    parser.add_argument("--path", type=str, default="01week", help="target path")
    opt = parser.parse_args()
    return opt


if __name__ == "__main__":
    opt = parse_opt()

    # 디렉터리가 존재하는지 확인
    if not os.path.exists(opt.path):
        # 존재하지 않는 경우 디렉터리 생성
        os.makedirs(opt.path)
        print(f"디렉터리 '{opt.path}'가 생성되었습니다.")
    else:
        print(f"디렉터리 '{opt.path}'가 이미 존재합니다.")

    main(opt.number, opt.path)
