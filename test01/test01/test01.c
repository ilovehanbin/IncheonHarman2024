#include <stdio.h>

int test01(); // ������ Ÿ�� ����
void test02();
void test03();
void Dump(char* p, int len);
void Copy(char* p1, char* p2);


// github���� �����Ͽ����ϴ�.
main()
{
	//test01();
	//test02();
	test03();
}

int test01()
{
	char* str[] = { "Zero","One","Two","Three","Four","Five","Six","Seven","Eight","Nine" }; // ���ڿ� �迭(������ �迭)

	printf("���� Ű�� �Է��ϼ���. �ش� ���ܾ �˷��帮�ڽ��ϴ�. \n");
	printf("���α׷��� �����÷��� 'Q'�� ��������.\n\n");

	int n = 1;

	while (n)
	{
		printf(">");
		char a = getch(); // no echo : Ű��(�ƽ�Ű�ڵ尪)�� ������� �ʰ� ��ȯ
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

void test02() // ���ڿ��� ���ڹ迭
{
	char ca[] = "Hello"; // ca[0]:'H' .. ca[4]:'o', ca[5]:null
	for (int i = 0; i < 6; i++) // 0 ~ 5
	{
		printf("ca[%d] : %c  (%02x) [%08x]\n", i, ca[i], ca[i], ca + i); // 1 �� ����
	}

	//int ia[] = { 10,20,30,40,50 };
	//for (int i = 0; i < 6; i++) // 0 ~ 5
	//{
	//	printf("ia[%d] : %d  (%08x) [%08x]\n", i, ia[i], ia[i], ia + i); // 4 �� ���� --> ������ ����
	//}

	int ia2[2][3] = { 10,20,30,40,50,60 };
	for (int y = 0; y < 2; y++) // 0 ~ 2
	{
		for (int x = 0; x < 3; x++)
		{
			printf("ia2[%d][%d] : %d  [%08x]\n", y, x, ia2[y][x], ia2[y][x], ia2 + y); // 8 �� ���� --> �迭�� �����ͷ� ����߱� ����.
		}

	}

	//ca[2] -= 1;
	//ca[3] -= 1;

	//for (int i = 0; i < 10; i++) // 0 ~ 5
	//{
	//	printf("ca[%d] : %c  (%02x)\n", i, ca[i], ca[i]);
	//}
}

void test03()
{
	char buf[100];  // ���� �޸� ���� Ȯ��
	char* pBuf;		// ���� �޸� ���� ���� ��� ��ġ ����
	unsigned int addr;		// ��� ��ġ ������ ���� �Է� ����
	char kBuf[100]; // ��� ���ڿ� �Է��� ���� Ȯ�� --> ���ڿ� �Է½� ���� Ȯ�� �ʼ�!!

	printf("���� ������ �ּҴ� %d[%08x] �Դϴ�.\n", (unsigned int)buf, buf); // ���� �޸� ���� �ּ� Ȯ��
	printf("�Է��� ������ �ּҸ� �Է��ϼ��� : ");
	scanf("%d", &addr); // --> Ű���� �Է°��� ������ ������ ���� // ���� ���� �ּ� ����
	pBuf = buf + addr; // ���� ���� �ּ� ����
	printf("���ڿ��� �Է��ϼ��� : ");
	scanf("%s", kBuf);
	Copy(pBuf, kBuf); // ���ڿ� ����
	Dump(buf, 100);
}

void Copy(char* p1, char* p2)
{
	while (*p2) *p1++ = *p2++; *p1 = 0;
}

void Dump(char* p, int len) // �޸� ���� ���, 16byte, �� �տ��� �ּ� ���Ĵ� 8���� ��� �ٹٲ� �� �ݺ�
{
	for (int i = 0; i < len; i++) // ���� ���� �޸� ����(����Ʈ ������ ���)
	{
		if (i % 16 == 0) printf("\n%08x ", p); // �ּҰ� ���
		if (i % 8 == 0) printf("    ");
		printf("%02x ", (unsigned char)*p++); // �ش� �ּҿ� �ִ� �� ���

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
			printf("���ڰ� �ƴմϴ�!!\n");
			break;
			*/
