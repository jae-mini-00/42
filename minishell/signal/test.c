#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <termios.h>
#include <string.h>
#include <errno.h>

static volatile sig_atomic_t g_stop = 0;

// 시그널 핸들러
void handle_sigint(int signo)
{
    // 여기에 원하는 동작(로그, 처리 등)을 작성
    // 예: 시그널 발생 사실 알림 후, 읽기 반복 루프 탈출하도록 플래그 세팅
    write(STDOUT_FILENO, "\nCaught SIGINT\n", 15);
    g_stop = 1;
}

// 논 캐너니컬 모드 설정
static int set_noncanonical_mode(struct termios *oldt)
{
    struct termios newt;

    // 현재 터미널 설정을 가져옴
    if (tcgetattr(STDIN_FILENO, oldt) < 0) {
        perror("tcgetattr");
        return -1;
    }

    // 복사 후 수정
    newt = *oldt;
    // ICANON과 ECHO를 끄면 "논 캐너니컬 모드" + "입력 에코 끔"
    newt.c_lflag &= ~(ICANON | ECHO);

    // 버퍼가 비면 즉시 read()가 리턴되도록 설정
    newt.c_cc[VMIN] = 1;  // 최소 1byte 입력 후 리턴
    newt.c_cc[VTIME] = 0; // 시간 제한 없음

    // 변경된 설정을 터미널에 적용
    if (tcsetattr(STDIN_FILENO, TCSANOW, &newt) < 0) {
        perror("tcsetattr");
        return -1;
    }
    return 0;
}

int main(void)
{
    // 시그널 핸들러 등록 (SA_RESTART 없이)
    struct sigaction act;
    memset(&act, 0, sizeof(act));
    act.sa_handler = handle_sigint;
    sigemptyset(&act.sa_mask);
    // SA_RESTART를 명시적으로 사용하지 않음 (act.sa_flags = 0)
    if (sigaction(SIGINT, &act, NULL) < 0) {
        perror("sigaction");
        return 1;
    }



    // 터미널 원본 설정 저장용 구조체
    struct termios oldt;
    // 논 캐너니컬 모드 설정
    if (set_noncanonical_mode(&oldt) < 0) {
        return 1;
    }




    // 읽기 루프
    char buf[128];
    while (!g_stop) {
        ssize_t n = read(STDIN_FILENO, buf, sizeof(buf)-1);
        if (n < 0) {
            // 시그널로 인해 EINTR가 발생했는지 확인
            if (errno == EINTR) {
                // SIGINT 등으로 read()가 깨어남
                break;
            }
            perror("read");
            break;
        } else if (n == 0) {
            // EOF (Ctrl+D 등)
            break;
        } else {
            // 읽은 데이터 출력
            buf[n] = '\0'; // 문자열 끝 지정
            printf("Read: %s\n", buf);
        }
    }


	

    // 터미널 설정 복원
    if (tcsetattr(STDIN_FILENO, TCSANOW, &oldt) < 0) {
        perror("tcsetattr (restore)");
    }

    printf("Program exiting.\n");
    return 0;
}
