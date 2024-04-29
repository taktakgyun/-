import re
from bs4 import BeautifulSoup
from icecream import ic


def calculate_progress(readme_path):
    # README.md 파일 열기
    with open(readme_path, "r", encoding="utf-8") as file:
        contents = file.read()

    # 안풀린 문제 수 찾기
    not_completed_problems = contents.count("- [ ]")

    # 완료된 문제 수 계산
    completed_problems = contents.count("- [X]")

    # 진행도 계산
    progress = (
        completed_problems / (not_completed_problems + completed_problems)
    ) * 100

    return progress


def update_progress_in_readme(progress, readme_path):
    # README.md 파일 열기
    with open(readme_path, "r", encoding="utf-8") as file:
        contents = file.read()

    # 진행도 표시 업데이트

    progress_format = f'<div class="progress" style="width: '

    # 정규 표현식을 사용하여 포맷이 존재하는지 확인
    if re.search(re.escape(progress_format), contents):
        # 진행률 업데이트
        progress_style = (
            f'<div class="progress" style="width: {(int(progress))}%;"></div>'
        )
        updated_contents = re.sub(
            r'<div class="progress" style="width: \d+%;">', progress_style, contents
        )
    else:
        updated_contents = (
            contents
            + f"""

진행상황
===
<div class="progress-bar">
  <div class="progress" style="width: {int(progress)}%;"></div>
</div>
"""
            + """
<style>
.progress-bar {
  background-color: #f0f0f0;
  border-radius: 5px;
  height: 20px;
  width: 300px;
  margin-bottom: 10px;
}

.progress {
  background-color: #4caf50;
  height: 100%;
  border-radius: 5px;
  text-align: center;
  color: white;
}
</style>
"""
        )

    # README.md 파일에 업데이트된 내용 쓰기
    with open(readme_path, "w", encoding="utf-8") as file:
        file.write(updated_contents)


if __name__ == "__main__":
    readme_path = "01week/README.md"
    progress = calculate_progress(readme_path)
    print(f"현재 진행도: {progress}%")

    # README.md 파일에 진행도 업데이트
    update_progress_in_readme(progress, "README.md")
