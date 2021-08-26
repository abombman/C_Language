#define _CRT_SECURE_NO_WARNINGS
#include"contact.h"

static int  Findbyname(const struct contact* ps, char* name)
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (0 == strcmp(ps->data[i].name, name))
			return i;
	}	
	return -1;
	
}

void Initcontact(struct contact* ps)
{
	ps->data = (struct peoinfo*)malloc(DEFAULT_SZ*sizeof(struct peoinfo));
	if (NULL == ps->data)
	{
		printf(" %s\n", strerror(errno));
		return;
	}
	//memset(ps->data, 0, DEFAULT_SZ * sizeof(struct peoinfo));
	ps->size = 0;
	ps->capacity = DEFAULT_SZ;
}

static int  Checkcapacity(struct contact* ps)
{
	struct peoinfo* ptmp = NULL;
	if (ps->size == ps->capacity)
	{
		ptmp = (struct peoinfo*)realloc(ps->data, (ps->capacity + 2) * sizeof(struct peoinfo));
		if (NULL == ptmp)
		{
			return -1;
		}
		else
		{
			ps->data = ptmp;
			ps->capacity += 2;
		}
	}
	return 0;
}

void Addcontact(struct contact* ps)
{
	int ret = Checkcapacity(ps);
	
	if (-1 == ret)
	{
		return;
	}

		printf("\ninput name:");
		ret = scanf("%s", ps->data[ps->size].name);
		printf("\ninput age:");
		ret = scanf("%d", &(ps->data[ps->size].age));
		printf("\ninput gender:");
		ret = scanf("%s", ps->data[ps->size].gender);
		printf("\ninput tele:");
		ret = scanf("%s", ps->data[ps->size].tele);
		printf("\ninput addr:");
		ret = scanf("%s", ps->data[ps->size].address);
		ps->size++;
		printf("\nsuccessfully added.\n");
}

void Showcontact(const struct contact* ps)
{
	int i = 0;
	if (0 == ps->size)
	{
		printf("empty list!\n");
	}
	else
	{
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "name", "age", "gender","tele", "address");
		for (i = 0; i < ps->size; i++)
		{
			printf("%-20s\t%-4d\t%-5s\t%-12s\t%-20s\n",
				ps->data[i].name,
				ps->data[i].age,
				ps->data[i].gender,
				ps->data[i].tele,
				ps->data[i].address);
		}
	}
}

void Delcontact(struct contact* ps)
{
	int pos, ret, j;
	char name[MAX_NAME] = {"0"};
	printf("input name:");
	ret = scanf("%s", name);
	pos = Findbyname(ps, name);
	if (-1 == pos)
	{
		printf("Not exist\n");
	}
	else
	{
		for (j = pos; j < ps->size-1; j++)
		{
			ps->data[j] = ps->data[j + 1];
			//strcpy(ps->data[j].name , ps->data[j+1].name);
			//strcpy(ps->data[j].gender, ps->data[j+1].gender);
			//strcpy(ps->data[j].tele, ps->data[j+1].tele);
			//strcpy(ps->data[j].address, ps->data[j+1].address);
			//ps->data[j].age = ps->data[j+1].age;
		}
		ps->size--;
		printf("Done\n");
	}
}

void Searchcontact(const struct contact* ps)
{
	int ret, pos;
	char name[MAX_NAME] = { "0" };
	printf("input name:");
	ret = scanf("%s", name);
	pos = Findbyname(ps, name);
	if (-1 == pos)
	{
		printf("Not exist\n");
	}
	else
	{
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "name", "age", "gender", "tele", "address");
		printf("%-20s\t%-4d\t%-5s\t%-12s\t%-20s\n",
				ps->data[pos].name,
				ps->data[pos].age,
				ps->data[pos].gender,
				ps->data[pos].tele,
				ps->data[pos].address);
		
	}
}

void Modifycontact(struct contact* ps)
{
	int ret, pos;
	char name[MAX_NAME] = { "0" };
	printf("input name:");
	ret = scanf("%s", name);
	pos = Findbyname(ps, name);
	if (-1 == pos)
	{
		printf("Not exist\n");
	}
	else
	{
		printf("\ninput name:");
		ret = scanf("%s", ps->data[pos].name);
		printf("\ninput age:");
		ret = scanf("%d", &(ps->data[pos].age));
		printf("\ninput gender:");
		ret = scanf("%s", ps->data[pos].gender);
		printf("\ninput tele:");
		ret = scanf("%s", ps->data[pos].tele);
		printf("\ninput addr:");
		ret = scanf("%s", ps->data[pos].address);	
		printf("\nsuccessfully modified.\n");
	}
}

void Destroycontact(struct contact* ps)
{
	free(ps->data);
	ps->data = NULL;
}