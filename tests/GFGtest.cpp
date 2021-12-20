#include <gtest/gtest.h>
#include "../GFG_operations.h"

TEST(TestGFG, LinksExists) {
	FILE* f = fopen("../search_results/Links.txt", "r");
	ASSERT_TRUE(f != NULL);
}

TEST(TestGFG, CodesFolderExists) {
	FILE* f = fopen("../search_results/Codes", "r");
	ASSERT_TRUE(f != NULL);
}

TEST(TestGFG, CodesExists) {
	GFG_operations gfg();
	FILE* f = fopen("../search_results/Codes/0_C++.txt", "r");
	ASSERT_TRUE(f != NULL);
	f = fopen("../search_results/Codes/1_php.txt", "r");
	ASSERT_TRUE(f != NULL);
	f = fopen("../search_results/Codes/2_C#.txt", "r");
	ASSERT_TRUE(f != NULL);
	f = fopen("../search_results/Codes/3_php.txt", "r");
	ASSERT_TRUE(f != NULL);
	f = fopen("../search_results/Codes/4_script.txt", "r");
	ASSERT_TRUE(f != NULL);
}
