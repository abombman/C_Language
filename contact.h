#pragma once
#include<stdio.h>
#include<string.h>

#define MAX 50
#define MAX_NAME 100
#define MAX_GENDER 5
#define MAX_TELE 12
#define MAX_ADDR 100

enum option
{
	EXIT,
    ADD,
	DEL,
	SEARCH,
	MODIFY,
	SHOW,
	SORT
};

struct peoinfo
{
	char name[MAX_NAME];
	int age;
	char gender[MAX_GENDER];
	char tele[MAX_TELE];
	char address[MAX_ADDR];

};

struct contact
{
	struct peoinfo data[MAX];
	int size;
};


void Initcontact(struct contact*);
void Addcontact(struct contact*);
void Showcontact(const struct contact*);
void Delcontact(struct contact*);
void Searchcontact(const struct contact*);
void Modifycontact(struct contact*);