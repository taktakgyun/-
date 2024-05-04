# 코딩테스트
코딩테스트 문제들을 보고 열심히 공부한다.
<br>주로 큰돌의 "10주완성 C++ 코딩테스트 | 알고리즘 코딩테스트" 문제를 풀고, 그 이후에 자유롭게 문제를 풀 예정입니다.

# Python 코드 실행하기
### progress.py 실행하기
푼 문제에 대해서 주차마다 진행도를 업데이트 해준다.
```bash
python progress.py --dir <목표폴더경로>
# ex)
python progress.py --dir 01week
```

### makeproblem.py 실행하기
백준 문제 번호를 입력하면, 해당 문제를 마크다운으로 변경해 준다.
```bash
python makeproblem.py --number <백준번호> --path <목표경로>
# ex)
python makeproblem.py --number 10808 --path 01week
```

### makeweek.py 코드 실행하기
백준 문제 리스트가 담겨있는 `READEME.md` 파일을 입력하면 해당 백준 문제들을 읽고 마크다운으로 변경해 준다.
```bash
python makeweek.py --readme <소스파일위치> --output <목표폴더경로>
# ex)
python makeweek.py --readme 01week/README.md --output 01week
```

# C++ 코드 실행하기
```bash
g++ -std=c++14 -Wall a.cpp -o test.out
./test.out
```

진행상황
===

01week : ![](https://geps.dev/progress/58)<br>
02week : ![](https://geps.dev/progress/0)<br>
