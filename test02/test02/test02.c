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
	char buf[100];  // ���� �޸� ���� Ȯ��
	char* pBuf;		// ���� �޸� ���� ���� ��� ��ġ ����
	unsigned int addr;		// ��� ��ġ ������ ���� �Է� ����
	char kBuf[100]; // ��� ���ڿ� �Է��� ���� Ȯ�� --> ���ڿ� �Է½� ���� Ȯ�� �ʼ�!!

	printf("���� ������ �ּҴ� %d[%08x] �Դϴ�.\n", (unsigned int)buf, buf); // ���� �޸� ���� �ּ� Ȯ��
	printf("�Է��� ������ �ּҸ� �Է��ϼ��� : "); // 
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