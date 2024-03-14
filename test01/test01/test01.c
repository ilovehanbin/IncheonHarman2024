#include <stdio.h>

void test01(); // 프로토 타입 선언
void test02();
void test03();
void test04();
void test05();
void test06();
void test07();
void test08();

void Dump(char* p, int len);
void Copy(char* p1, char* p2);

int Length(char* str);
int Compare(char* s1, char* s2);


main()
{
	int n;
	void* pF[] = { test01, test02, test03, test04, test05, test06, test07, test08 }; // void* : 타입이 정해지지 않은 포인터, 각 함수의 주소가 배열에 저장됨.
	void (*pFunc)(); // 함수 포인터 선언	


	while (1)
	{
		printf("\n");
		printf("1. 숫자키에 대한 문자열 출력 미션\n");
		printf("2. 문자열과 문자배열\n");
		printf("3. 포인터의 위치 지정\n");
		printf("4. 포인터를 이용한 문자열 입출력함수\n");
		printf("5. 구조체 테스트\n");
		printf("6. 표준 함수 테스트\n");
		printf("7. Length 함수 테스트\n");
		printf("8. Compare 함수 테스트\n");
		printf("0. 종  료\n");
		printf("=====================================\n");
		printf("선택 : ");
		scanf("%d", &n);

		if (n == 0) return; // 0 눌렀을 때 프로그램 종료
		pFunc = pF[n - 1]; // 함수 포인터에 번호에 따른 함수 주소 저장
		pFunc(); // 함수 호출
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
	scanf("%s", buf + 50);
	arr[7] = buf + 50;

	for (int i = 0; i < 10; i++)
	{
		printf("arr[%d] : 0x%08x  %s\n",i,arr[i],arr[i]); // 문자열이 저장된 위치 출력
	}
}

void test05() // 구조체 테스트
{
	struct stTest
	{
		int i; // 4 byte
		float a; // 4 byte
		char name[20]; // 20 byte를 고정적으로 할당 하므로 메모리 낭비가 될 수도 있음. 그러나 안정적으로 사용하기 위해서는 크게 할당해야 함.
		//char* name; // 주소는 무조건 8 byte 크기를 갖는다.
	} s1 = { 1, 3.14, "삼천갑자 동방삭" };
	//s1.name = "삼천갑자 동방삭"; 

	struct stTest s2 = s1; // 문자열까지도 대입 가능

	printf("sizeof(struct stTest) : %d\n", sizeof(struct stTest)); // sizeof는 함수처럼 보이지만 함수가 아니라 매크로. 그러나 함수처럼 생각해도 무관. 변수의 총 byte 수 반환

	printf("struct stTest s1 : %d  %f  %s\n", s1.i, s1.a, s1.name);
	printf("struct stTest s2 : %d  %f  %s\n", s2.i, s2.a, s2.name);	
}

void test06() // 표준 함수 테스트
{
	char* s1; //= "Good";
	char* s2; //= "afternoon";

	char buf[100]; // 안전 공간 확보

	s1 = buf; // buf의 주소가 s1에 저장
	s2 = buf + 50; // buf의 50번째 위치 주소가 s2에 저장

	scanf("%s\n", s1 = buf); 
	scanf("%s\n", s2 = buf + 50); 

	// strcat Test
	printf("s1 : %s(%d)\n", s1, strlen(s1)); // strlen 함수는 null을 포함하지 않고 길이를 센다.
	printf("s2 : %s(%d)\n", s2, strlen(s2));

	strcpy(buf, s1); // 연장될 대상 문자열 안전 공간에 저장
	strcat(buf, s2); // 문자열 덧붙이기
	// strcat은 문자열 뒤에 새로운 문자열을 연장하여 덧붙일 수 있는 함수.
	// 문자열이 수정 불가 영역에 있을 경우 연장이 불가능하므로 해당 문자열을 안전 공간에 저장해야 한다.

	printf("strcat(s1,s2) : %s\n", buf); 

	//1. 안전 공간에 문자열을 저장하여 사용하는 방법
	//char buf[100]; 사용하기
	// 
	//2. sprintf 함수를 사용하는 방법
	//strcat 사용하지 않기
	// 
	//sprintf(buf, "strcat(s1,s2) : %s %s\n", s1, s2); // s1과 s2를 buf 에 담음
	//printf("%s", buf);	
}

void test07()
{
	char buf[100];
	
	printf("문자열을 입력하세요 : ");
	scanf("%s", buf);
	printf("입력한 문자열의 길이는 [%d] 입니다.\n", Length(buf));
}

void test08()
{
	char buf1[100];
	char buf2[100];

	printf("첫 번째 문자열을 입력하세요 : ");
	scanf("%s", buf1);
	printf("두 번째 문자열을 입력하세요 : ");
	scanf("%s", buf2);
	printf("두 문자열 비교 결과는 [%d] 입니다.\n", Compare(buf1, buf2));
}

// ------- 함수의 설계 ------
// Prototype : int Length(char* str)
// 함수명 : Length
// 기능 : 문자열을 인수로 받아서 문자열의 길이를 반환
// 인수 : 문자열 - char* str
// 리턴값 : 문자열의 길이 - int len 

int Length(char* str) // strlen 함수와 같은 기능
{
	int len = 0;

	while (1)
	{
		if (*(str + len) == 0) break; // 문자열의 끝(null)에 도달했으면 탈출
		len++;
	}

	return len;
	
	/*int len;
	char buf[100];
	str = buf;

	scanf("%s\n", str);
	for (len = 0; str[len] == 0 ; len++);
	printf("문자열의 길이 : %d\n", len);
	return len;*/
}

// ------- 함수의 설계 -------
// Prototype : int Compare(char* p1,char* p2)
// 함수명 : Compare
// 기능 : s1 문자열과 s2 문자열을 byte 단위로 비교하여 그 비교 결과를 반환
// 인수 : 비교문자열1, 비교문자열2 - char* s1,char* s2
// 리턴값 : int

int Compare(char* s1, char* s2)  
{	
	int val = 0;
	
	while ((*s1) && (*s2) && (*s1 == *s2)) 
	{
		s1++;
		s2++;
	}

	if (*s1 - *s2 > 0) val = 1;
	else if (*s1 - *s2 == 0) val = 0;
	else if (*s1 - *s2 < 0) val = -1;

	return val;
}

// ------- 함수의 설계 -------
// Prototype : void Copy(char* p1,char* p2)
// 함수명 : Copy
// 기능 : p2 문자열을 인수로 받아서 p1 문자열로 복사
// 인수 : 타겟문자열, 소스문자열 - char* p1,char* p2
// 리턴값 : void

void Copy(char* p1, char* p2) // strcpy 함수와 같은 기능
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



