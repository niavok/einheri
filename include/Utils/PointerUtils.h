/*
 * PointerUtils.h
 *
 *  Created on: 9 juil. 2010
 *      Author: thomas
 */

#ifndef POINTERUTILS_H_
#define POINTERUTILS_H_

namespace einUtils {

/**
 * @brief take two pointer and copy the right one into the left one.
 * if left or right are NULL nothing is done.
 */
template <typename T>
void copy(T* left, T* right)
{
    if (left != NULL && right != NULL && left != right)
    {
        *left = *right;
    }
}

/**
 * @brief Use the copy constructor to create a new T.
 */
template <typename T>
void copyConstruct(T*& left, T* right)
{
    if (right != NULL && left != right)
    {
        left = new T(*right);
    }
}

/**
 * @brief perform a "deep compare" on two pointers.
 * It verify if the pointer are NULL before actually comparing them.
 */
template <typename T, typename U>
bool compare(T* left, U* right)
{
    if(left == right)
    {
        return true;
    }
    if (left != NULL && right != NULL)
    {
        return *left == *right;
    }
    return false;
}



}  // namespace ELS

#endif /* POINTERUTILS_H_ */
