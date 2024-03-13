#include <stdio.h>

void test03();
void Dump(char* p, int len);
void Copy(char* p1, char* p2);

main()
{
	
	test03();
}

void test03()
{
	char buf[100];  // 안전 메모리 공간 확보
	char* pBuf;		// 안전 메모리 공간 중의 출력 위치 지정
	unsigned int addr;		// 출력 위치 지정을 위한 입력 변수
	char kBuf[100]; // 출력 문자열 입력할 공간 확보 --> 문자열 입력시 공간 확보 필수!!

	printf("안전 공간의 주소는 %d[%08x] 입니다.\n", (unsigned int)buf, buf); // 안전 메모리 공간 주소 확인
	printf("입력을 시작할 주소를 입력하세요 : "); // 
	scanf("%d", &addr); // --> 키보드 입력값을 포인터 변수에 저장 // 안전 공간 주소 참고
	pBuf = buf + addr; // 안전 공간 주소 연결
	printf("문자열을 입력하세요 : ");
	scanf("%s", kBuf);
	Copy(pBuf, kBuf); // 문자열 복사
	Dump(buf, 100);
}

void Copy(char* p1, char* p2)
{
	while (*p2) *p1++ = *p2++; *p1 = 0;
}

void Dump(char* p, int len) // 메모리 공간 출력, 16byte, 맨 앞에는 주소 이후는 8개씩 출력 줄바꿈 후 반복
{
	for (int i = 0; i < len; i++) // 안전 공간 메모리 덤프(바이트 단위로 출력)
	{
		if (i % 16 == 0) printf("\n%08x ", p); // 주소값 출력
		if (i % 8 == 0) printf("    ");
		printf("%02x ", (unsigned char)*p++); // 해당 주소에 있는 값 출력

	}
}