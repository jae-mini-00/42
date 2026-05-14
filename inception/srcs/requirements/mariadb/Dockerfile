FROM debian:bullseye

# 패키지 설치 및 패키지 목록 업데이트
# 서버 설치(실제 엔진)
# 명렁어 클라이언트 설치(DB생성, 유저 생성 같은 명령어)
# 컨테이너에서 프로세스 관리를 좀 더 안정적으로 해주는 패키지
# 패키지 설치 후에 남는 캐시 정리
RUN apt-get update && apt-get install -y \
    mariadb-server \
    mariadb-client \
    dumb-init \
    && apt-get clean \
    && rm -rf /var/lib/apt/lists/*

# 호스트에 있는 파일을 컨테이너 안으로 복사(스크립트를 이용)
# tools/init.sh에 있는 파일을 복사해서 
# 현재 위치에 init.sh로 복사해서 파일 생성
COPY ./tools/init.sh /init.sh

# 살행 권한 주기
RUN chmod +x /init.sh

# MariaDB의 포트 번호 쓴 다는 표시
EXPOSE 3306

# 컨테이너가 시작할 때 “항상 앞에서 실행될 고정 프로그램”
# 컨테이너가 시작하면 무조건 /usr/bin/dumb-init부터 실행하겠다.
# "--" 은 dumb-init의 옵션이 끝났음을 의미
ENTRYPOINT [ "/usr/bin/dumb-init", "--" ]
# 컨테이너 시작 시 기본으로 실행할 명령 또는 인자
CMD [ "/init.sh" ]