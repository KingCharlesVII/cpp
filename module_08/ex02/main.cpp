#include <iostream>
#include <vector>
#include <cstdlib>
#include <exception>

#include "MutantStack.hpp"

int main()
{
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
    std::cout << *it << std::endl;
    ++it;
    }
    std::stack<int> s(mstack);
    return 0;
}

/*
#include <iostream>
#include <list>
#include <stack>

#include "MutantStack.hpp"

int main()
{
    std::cout << "===== Subject test =====" << std::endl;

    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);

    std::cout << mstack.top() << std::endl;

    mstack.pop();

    std::cout << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    ++it;
    --it;

    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }

    std::stack<int> s(mstack);

    std::cout << "\n===== Reverse iterator test =====" << std::endl;

    MutantStack<int>::iterator rit = mstack.end();

    while (rit != mstack.begin())
    {
        --rit;
        std::cout << *rit << std::endl;
    }

    std::cout << "\n===== Copy constructor test =====" << std::endl;

    MutantStack<int> copy(mstack);

    MutantStack<int>::iterator copyIt = copy.begin();
    MutantStack<int>::iterator copyIte = copy.end();

    while (copyIt != copyIte)
    {
        std::cout << *copyIt << std::endl;
        ++copyIt;
    }

    std::cout << "\n===== Assignment operator test =====" << std::endl;

    MutantStack<int> assigned;

    assigned = mstack;

    MutantStack<int>::iterator assignedIt = assigned.begin();
    MutantStack<int>::iterator assignedIte = assigned.end();

    while (assignedIt != assignedIte)
    {
        std::cout << *assignedIt << std::endl;
        ++assignedIt;
    }

    std::cout << "\n===== Const iterator test =====" << std::endl;

    const MutantStack<int> constStack(mstack);

    MutantStack<int>::const_iterator constIt = constStack.begin();
    MutantStack<int>::const_iterator constIte = constStack.end();

    while (constIt != constIte)
    {
        std::cout << *constIt << std::endl;
        ++constIt;
    }

    std::cout << "\n===== Empty stack test =====" << std::endl;

    MutantStack<int> empty;

    if (empty.begin() == empty.end())
        std::cout << "Empty stack: begin() == end()" << std::endl;

    std::cout << "\n===== std::list comparison =====" << std::endl;

    std::list<int> list;

    list.push_back(5);
    list.push_back(3);
    list.push_back(5);
    list.push_back(737);
    list.push_back(0);

    std::list<int>::iterator listIt = list.begin();
    std::list<int>::iterator listIte = list.end();

    while (listIt != listIte)
    {
        std::cout << *listIt << std::endl;
        ++listIt;
    }

    return 0;
}
*/