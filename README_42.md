# 42 GYEONGSAN Projects

42 GYEONGSAN에서 진행한 C/C++ 기반 프로젝트를 정리한 저장소입니다.  
자기주도 학습과 동료평가를 통해 시스템 프로그래밍, 그래픽스, 네트워크 프로그래밍 및 협업 경험을 쌓았습니다.

## 주요 프로젝트

| 프로젝트 | 기술 | 설명 |
| --- | --- | --- |
| [miniRT](./miniRT) | C, MiniLibX, Vector Math | Ray Tracing 기반의 3D 렌더러 |
| [webserv](./webserve) | C++98, HTTP/1.1, epoll | 논블로킹 HTTP 웹 서버 |
| [FDF](./FDF) | C, MiniLibX | 높이맵 기반 3D 와이어프레임 렌더러 |
| [Minishell](./minishell) | C, Unix Process, Readline | Bash의 주요 기능을 재현한 Unix Shell |

---

## miniRT — C 기반 Ray Tracing 렌더러

카메라에서 화면의 각 픽셀을 통과하는 광선을 장면으로 역추적하여 객체와의 교차점, 조명 및 그림자를 계산하는 렌더러입니다.

### 주요 기능

- 구, 평면, 원기둥 등 객체와 광선의 교차 판정
- Phong 조명 모델을 이용한 표면 색상 계산
- 카메라, 광원 및 객체의 이동·회전
- `.rt` 장면 파일 파싱 및 입력값 검증
- MiniLibX를 이용한 렌더링 결과 출력

### 담당 업무

- 벡터 및 광선 계산 등 Ray Tracing 핵심 연산을 기능 단위의 함수로 분리
- 객체·카메라·광원의 이동 및 회전 기능 구현
- 장면 파일의 객체, 카메라, 광원 데이터 파싱
- 파싱 데이터의 형식 및 범위 검증과 렌더링용 자료구조 변환

### 실행

```bash
cd miniRT
make
./miniRT map.rt
```

---

## webserv — C++98 기반 HTTP 웹 서버

C++98로 구현한 논블로킹 HTTP/1.1 웹 서버입니다. Linux `epoll`을 이용해 단일 이벤트 루프에서 여러 클라이언트의 요청을 처리합니다.

### 주요 기능

- HTTP 요청 파싱 및 응답 생성
- `GET`, `POST`, `DELETE` 요청 처리
- 정적 파일 제공 및 디렉터리 자동 인덱싱
- CGI 실행
- 파일 업로드
- 설정 파일 기반 서버 및 라우팅 규칙 구성
- 요청 오류, 연결 종료 및 타임아웃 처리

### 담당 업무

- 서버 설정 파일 파싱 및 내부 설정 객체 구성
- 잘못된 키워드, 중복 설정, 값 누락 등 설정 문법 오류 검증
- 설정된 Rewrite 규칙에 따른 요청 URI 변경 처리
- 클라이언트 요청 URI와 Location 규칙의 매칭 로직 구현
- 여러 Location 후보 중 요청에 적합한 규칙을 선택하는 처리 구현

### 실행

```bash
cd webserve
make
./webserv configs/default.wbsrv
```

자세한 웹 서버 설명은 [webserve/README.md](./webserve/README.md)에서 확인할 수 있습니다.

---

## FDF — C 기반 3D 와이어프레임 렌더러

높이값으로 구성된 맵 파일을 읽어 3차원 지형으로 변환하고, 화면에 와이어프레임 형태로 출력하는 그래픽스 프로젝트입니다.

### 주요 기능

- `.fdf` 맵의 높이 및 색상 데이터 파싱
- 3차원 좌표의 2차원 화면 투영
- 인접 좌표를 연결하는 선분 렌더링
- 높이값에 따른 색상 표현
- 확대·축소 및 화면 이동
- X·Y·Z축 기준 회전
- 투영 방식 전환

### 구현 내용

- 맵 데이터를 동적 자료구조에 저장하고 메모리 수명 관리
- 좌표 변환 및 투영 계산
- 픽셀 기반 선분 렌더링
- 키보드 입력을 이용한 이동, 회전, 확대·축소 기능 구현
- 필수 기능과 보너스 기능 전체 구현

### 실행

```bash
cd FDF
make bonus
./fdf maps/test_maps/42.fdf
```

---

## Minishell — C 기반 Unix Shell

Bash의 기본 동작을 참고하여 명령어 실행, 빌트인 명령어, 파이프, 리다이렉션 및 환경변수 처리를 구현한 팀 프로젝트입니다.

### 주요 기능

- 명령어 입력 및 히스토리 관리
- 명령어 토큰화와 환경변수 확장
- `echo`, `cd`, `pwd`, `export`, `unset`, `env`, `exit` 빌트인 명령어
- `fork`, `execve`, `pipe`, `dup2`, `waitpid`를 이용한 명령 실행
- 파이프와 입출력 리다이렉션
- Here Document
- 시그널 및 종료 상태 처리

### 담당 업무

- 빌트인 명령어 구현
- 파이프 및 멀티프로세스 실행 구조 구현
- 프로세스 간 표준 입력·출력 연결
- 자식 프로세스의 실행과 종료 상태 관리
- GitHub Pull Request와 코드 리뷰를 통한 팀 협업

### 실행

```bash
cd minishell
make
./minishell
```

---

## 기술 스택

### Language

- C
- C++98

### System Programming

- Linux / Unix
- Process, Pipe, Signal
- File Descriptor
- Socket, TCP/IP, HTTP
- Non-blocking I/O, epoll

### Graphics

- MiniLibX
- Vector and Matrix Operations
- Projection
- Ray Tracing
- Phong Lighting

### Tools

- Git / GitHub
- Makefile
- GDB
- Valgrind

---

## 학습 경험

프로젝트를 진행하며 단순히 기능을 구현하는 것에 그치지 않고 다음 역량을 학습했습니다.

- 요구사항을 기능 단위로 분해하고 모듈 간 책임을 구분하는 방법
- 동적 메모리와 파일 디스크립터 등 자원의 수명을 관리하는 방법
- 오류 상황과 경계값을 고려해 입력값을 검증하는 방법
- 팀원과 자료구조 및 인터페이스를 조율하는 방법
- 코드 리뷰 내용을 반영하고 문제 원인을 추적하는 방법
