#include <gtest.h>
#include "TQueue.h"

TEST(TQueue, can_get_current_size)
{
	TQueue tmp;

	EXPECT_EQ(0, tmp.getCurrentSize());
}

TEST(TQueue, can_add_and_get_objective)
{
	TQueue tmp;
	tmp.AddObjective(2, 1);
	TNode tmp2(2, 1);

	EXPECT_EQ(tmp2, tmp.GetObjective(0));
}

TEST(TQueue, cant_add_objective_in_full_queue)
{
	TQueue tmp;
	for (int i = 0; i < 20; i++)
		tmp.AddObjective(1, 1);

	ASSERT_ANY_THROW(tmp.AddObjective(1, 1));
}

TEST(TQueue, can_increase_priority)
{
	TQueue tmp;
	tmp.AddObjective(2, 3);
	tmp.IncreasePriority();
	tmp.IncreasePriority();
	TNode tmp2(2, 3);
	tmp2.Priority = 2;

	EXPECT_EQ(tmp2, tmp.GetObjective(0));
}

TEST(TQueue, can_delete_first_objective)
{
	TQueue tmp;
	tmp.AddObjective(2, 3);
	tmp.AddObjective(5, 3);
	tmp.DeleteObjective(0);
	TNode tmp2(5, 3);


	EXPECT_EQ(tmp2, tmp.GetObjective(0));
}

TEST(TQueue, can_delete_last_objective)
{
	TQueue tmp;
	tmp.AddObjective(2, 3);
	tmp.AddObjective(5, 3);
	tmp.DeleteObjective(1);
	TNode tmp2(2, 3);

	EXPECT_EQ(tmp2, tmp.GetObjective(0));
}

TEST(TQueue, can_delete_objective)
{
	TQueue tmp;
	tmp.AddObjective(2, 3);
	tmp.AddObjective(5, 3);
	tmp.AddObjective(1, 5);
	tmp.AddObjective(7, 4);
	tmp.DeleteObjective(2);
	TNode tmp2(7, 4);

	EXPECT_EQ(tmp2, tmp.GetObjective(2));
}