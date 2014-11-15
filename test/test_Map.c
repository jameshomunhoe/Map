#include "unity.h"
#include "Map.h"
#include "LinkedList.h"
#include "Student.h"
#include "mock_HashFunction.h"

void setUp(void){}

void tearDown(void){}

void test_createMap(void){
	Map *map = createMap(10);
	
	TEST_ASSERT_NOT_NULL(map);
	TEST_ASSERT_EQUAL(10, map->size);
	TEST_ASSERT_NOT_NULL(map->table);
}

void test_destroyMap(void){
	Map *map = createMap(10);
	
	destroyMap(map);
}

void test_addMap(void){
	LinkedList *firstList;
	Student ali = {.name = "ali", .age = 10};
	Map *map = createMap(10);
	
	hash_ExpectAndReturn((void *)&ali, 4);
	
	addMap(map, (void *)&ali, hash);
	firstList = map->table[4];
	TEST_ASSERT_NOT_NULL(map->table[4]);
	TEST_ASSERT_EQUAL_PTR(&ali, (Student *)(firstList->data));
}