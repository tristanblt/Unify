/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** test_tmp
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(Tmp, test_tu)
{
    cr_assert_eq(5, 5);
}