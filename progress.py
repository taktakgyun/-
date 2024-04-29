import re
import os
import argparse
from icecream import ic

readme = "README.md"


def calculate_progress(dir_path):
    # README.md 파일 열기
    with open(os.path.join(dir_path, readme), "r", encoding="utf-8") as file:
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


def update_progress_in_readme(progress, target_dir):
    # README.md 파일 열기
    with open(readme, "r", encoding="utf-8") as file:
        contents = file.read()


    # 진행도 표시 업데이트
    progress_format = f"{target_dir} : ![](https://geps.dev/progress/"

    # 정규 표현식을 사용하여 포맷이 존재하는지 확인
    if re.search(re.escape(progress_format), contents):
        # 진행률 업데이트
        progress_style = f"{target_dir} : ![](https://geps.dev/progress/{progress})<br>"
        updated_contents = re.sub(
            r"{target_dir} : ![](https://geps.dev/progress/\d+)<br>",
            progress_style,
            contents,
        )
    else:
        updated_contents = (
            contents + f"{target_dir} : ![](https://geps.dev/progress/{progress})<br>\n"
        )

    # README.md 파일에 업데이트된 내용 쓰기
    with open(readme, "w", encoding="utf-8") as file:
        file.write(updated_contents)


def parse_opt():
    parser = argparse.ArgumentParser(description="Update Progress")
    parser.add_argument(
        "--dir", type=str, default="01week", help="Path to the target directory."
    )
    opt = parser.parse_args()
    return opt


if __name__ == "__main__":
    opt = parse_opt()

    dir_path = opt.dir
    progress = calculate_progress(dir_path)
    print(f"{dir_path} 현재 진행도: {progress}%")

    # README.md 파일에 진행도 업데이트
    update_progress_in_readme(int(progress), dir_path)
