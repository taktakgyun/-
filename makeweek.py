import re
import os
import argparse
import makeproblem
from typing import List

def extract_problem_numbers(contents):
    ## 백준 문제 번호 추출
    problem_numbers = re.findall(r'(?<=:)\s*\d+\s*(?=[-–])', contents)
    # 백준 문제 알파벳 추출
    problem_alpabates = re.findall(r'(?<=[-–])\s*[A-Za-z]\s*(?=:)', contents)
    return list(map(lambda n, a:(a.strip(),n.strip()) ,problem_numbers, problem_alpabates))

def main(src, dst):
    # src, dst 존재하는지 확인
    assert os.path.exists(src), f"'{src}'가 존재하지 않습니다."
    assert os.path.getsize(src) > 0, f"'{src}'는(은) 비어있는 파일입니다."
    assert os.path.exists(dst), f"'{dst}'가 존재하지 않습니다."
    
    # README.md 파일 열기
    with open(src, 'r', encoding='utf-8') as file:
        contents = file.read()
    
    problems = extract_problem_numbers(contents)

    err_num = []
    for a,n in problems:
        target_path = f"{dst}/{a}-{n}.md"
        # 파일이 빈 파일인지 확인
        if os.path.isfile(target_path) and os.path.getsize(target_path) > 0:
            print(target_path, "는 이미 완료된 파일입니다.")
            continue
        
        try:
            postprocess_text = makeproblem.convert_markdown(n)
        except ValueError:
            print(f"convert_markdown err : {n}")
            err_num.append(target_path)
            continue
        
        makeproblem.make_markdown_file(target_path, postprocess_text)
    
    if len(err_num) >0:
        print("err list\n=============================")
        for i, n in enumerate(err_num):
            print(f"{(i+1)} : {n}")

def parse_opt():
    parser = argparse.ArgumentParser(description='Convert Baekjoon problem list in README.md to Markdown format')
    parser.add_argument('--readme', type=str, default="01week/README.md", help='Path to the README.md file')
    parser.add_argument('--output', type=str, default=None, help='Path to the output file')
    opt = parser.parse_args()
    return opt

if __name__ == "__main__":
    opt = parse_opt()
    assert isinstance(opt.readme,str), "Type of readme is str fliename. ex> --readme 01week/README.md"
    readme = opt.readme
    
    if not isinstance(opt.output,str):
        output = os.path.dirname(opt.readme)
    else:
        output = opt.output
    assert isinstance(output,str), "Type of output is str path. ex> --output 01week"
        
    # 디렉터리가 존재하는지 확인
    if not os.path.exists(output):
        # 존재하지 않는 경우 디렉터리 생성
        os.makedirs(output)
        print(f"디렉터리 '{output}'가 생성되었습니다.")
    
    main(readme, output)