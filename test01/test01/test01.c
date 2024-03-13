#include <stdio.h>

void test01(); // 프로토 타입 선언
void test02();
void test03();
void test04();
void Dump(char* p, int len);
void Copy(char* p1, char* p2);


main()
{
	int n;
	void* pF[] = { test01, test02, test03, test04 }; // void* : 타입이 정해지지 않은 포인터, 각 함수의 주소가 배열에 저장됨.
	void (*pFunc)(); // 함수 포인터 선언

	while (1)
	{
		printf("\n\n\n\n\n");
		printf("1. 숫자키에 대한 문자열 출력 미션\n");
		printf("2. 문자열과 문자배열\n");
		printf("3. 포인터의 위치 지정\n");
		printf("4. 포인터를 이용한 문자열 입출력함수\n");
		printf("0. 종  료\n");
		printf("=====================================\n");
		printf("선택 : ");
		scanf("%d", &n);

		if (n == 0) return; // 0 눌렀을 때 프로그램 종료
		pFunc = pF[n - 1];
		pFunc();
	}
	

	//test01();
	//test02();
	//test03();
	//test04();
}

void test01() // 숫자키에 대한 문자열 출력 미션
{
	char* str[] = { "Zero","One","Two","Three","Four","Five","Six","Seven","Eight","Nine" }; // 문자열 배열(포인터 배열)

	printf("숫자 키를 입력하세요. 해당 영단어를 알려드리겠습니다. \n");
	printf("프로그램을 끝내시려면 'Q'를 누르세요.\n\n");

	int n = 1;

	while (n)
	{
		printf(">");
		char c = getch(); // no echo : 키값(아스키코드값)을 출력하지 않고 반환
		//int m = c - 0x30; // ASCII --> num

		if ((c | 0x20) == 'q') break;
		printf(" %c : %s\n", c, str[c - 0x30]);

		/*switch (a)
		{
		case '1': printf(" %c : One\n", a); break;
		case '2': printf(" %c : Two\n", a); break;
		case '3': printf(" %c : Three\n", a); break;
		case '4': printf(" %c : Four\n", a); break;
		case '5': printf(" %c : Five\n", a); break;
		case '6': printf(" %c : Six\n", a); break;
		case '7': printf(" %c : Seven\n", a); break;
		case '8': printf(" %c : Eight\n", a); break;
		case '9': printf(" %c : Nine\n", a); break;
		case '0': printf(" %c : Zero\n", a); break;
		case 'q':
		case 'Q': n = 0; break;
		}		*/

		/*if (a == '1') printf(" %c : One\n", a);
		else if (a == '2') printf(" %c : Two\n", a);
		else if (a == '3') printf(" %c : Three\n", a);
		else if (a == '4') printf(" %c : Four\n", a);
		else if (a == '5') printf(" %c : Five\n", a);
		else if (a == '6') printf(" %c : Six\n", a);
		else if (a == '7') printf(" %c : Seven\n", a);
		else if (a == '8') printf(" %c : Eight\n", a);
		else if (a == '9') printf(" %c : Nine\n", a);
		else if (a == '0') printf(" %c : Zero\n", a);
		else if (a | 0x20 == 'q') break;
		else
			printf("숫자가 아닙니다!!\n");
			break;
			*/
	}
}

void test02() // 문자열과 문자배열
{
	char ca[] = "Hello"; // ca[0]:'H' .. ca[4]:'o', ca[5]:null
	for (int i = 0; i < 6; i++) // 0 ~ 5
	{
		printf("ca[%d] : %c  (%02x) [%08x]\n", i, ca[i], ca[i], ca + i); // 1 씩 증가
	}

	//int ia[] = { 10,20,30,40,50 };
	//for (int i = 0; i < 6; i++) // 0 ~ 5
	//{
	//	printf("ia[%d] : %d  (%08x) [%08x]\n", i, ia[i], ia[i], ia + i); // 4 씩 증가 --> 포인터 연산
	//}

	int ia2[2][3] = { 10,20,30,40,50,60 };
	for (int y = 0; y < 2; y++) // 0 ~ 2
	{
		for (int x = 0; x < 3; x++)
		{
			printf("ia2[%d][%d] : %d  [%08x]\n", y, x, ia2[y][x], ia2[y][x], ia2 + y); // 8 씩 증가 --> 배열을 포인터로 사용했기 때문.
		}

	}

	//ca[2] -= 1;
	//ca[3] -= 1;

	//for (int i = 0; i < 10; i++) // 0 ~ 5
	//{
	//	printf("ca[%d] : %c  (%02x)\n", i, ca[i], ca[i]);
	//}
}

void test03() // 포인터의 위치 지정
{
	char buf[100];  // 안전 메모리 공간 확보
	char* pBuf;		// 안전 메모리 공간 중의 출력 위치 지정
	unsigned int addr;		// 출력 위치 지정을 위한 입력 변수
	char kBuf[100]; // 출력 문자열 입력할 공간 확보 --> 문자열 입력시 공간 확보 필수!!

	printf("안전 공간의 주소는 %d[%08x] 입니다.\n", (unsigned int)buf, buf); // 안전 메모리 공간 주소 확인
	printf("입력을 시작할 주소를 입력하세요 : ");
	scanf("%d", &addr); // --> 키보드 입력값을 포인터 변수에 저장 // 안전 공간 주소 참고
	pBuf = buf + addr; // 안전 공간 주소 연결
	printf("문자열을 입력하세요 : ");
	scanf("%s", kBuf);
	Copy(pBuf, kBuf); // 문자열 복사
	Dump(buf, 100);
}

void test04() // 포인터를 이용한 문자열 입출력함수
{
	char* arr[10] = { "aaaaa","bbbb","ccc","dd","eeeee"};
	char buf[100];

	printf("[6]  ");
	scanf("%s", buf);
	arr[6] = buf;

	printf("[7]  ");
	scanf("%s", buf+50);
	arr[7] = buf+50;

	for (int i = 0; i < 10; i++)
	{
		printf("arr[%d] : 0x%08x  %s\n",i,arr[i],arr[i]); // 문자열이 저장된 위치 출력
	}
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



