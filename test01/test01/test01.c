#include <stdio.h>

int test01(); // 프로토 타입 선언
void test02(int a);


// github에서 수정하였습니다.
main()
{
	//test01();
	test02(1);
}

int test01()
{
	char* str[] = {"Zero","One","Two","Three","Four","Five","Six","Seven","Eight","Nine"}; // 문자열 배열(포인터 배열)
	
	printf("숫자 키를 입력하세요. 해당 영단어를 알려드리겠습니다. \n");
	printf("프로그램을 끝내시려면 'Q'를 누르세요.\n\n");

	int n = 1;

	while (n)
	{
		printf(">");
		char a = getch(); // no echo : 키값(아스키코드값)을 출력하지 않고 반환
		int m = a - 0x30; // ASCII --> num

		printf(" %c : %s\n", a, str[m]);
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
	}	
}

void test02(int a) // 문자열과 문자배열
{
	char ca[] = "Hello"; // ca[0]:'H' .. ca[4]:'o', ca[5]:null
	for (int i = 0; i < 10; i++) // 0 ~ 5
	{
		printf("ca[%d] : %c  (%02x)\n", i, ca[i], ca[i]);
	}

	ca[2] -= 1;
	ca[3] -= 1;

	for (int i = 0; i < 10; i++) // 0 ~ 5
	{
		printf("ca[%d] : %c  (%02x)\n", i, ca[i], ca[i]);
	}
}

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
