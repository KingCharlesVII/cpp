#include <iostream>
#include <string>
#include <cstdlib>
#include <exception>

#include "Bureaucrat.hpp"

static std::size_t tests;

void    print_success() {
    std::cout << "Test " << tests << " passed" << std::endl;
    tests++;
}

#define ASSERT_EQ(actual, expected) \
    do { \
        if (actual != expected) {\
            std::cout << "[Error]: " << actual << " is different from " << expected << std::endl; \
            std::exit(1); \
        } \
        print_success(); \
    }   while (0)

#define ASSERT_NE(actual, expected) \
    do { \
        if (actual == expected) {\
            std::cout << "[Error]: " << actual << " is equal to " << expected << std::endl; \
            std::exit(1); \
        } \
        print_success(); \
    }   while (0)

#define ASSERT_TRUE(actual) \
    do { \
        if (actual == false) {\
            std::cout << "[Error]: " << actual << " is false" << std::endl; \
            std::exit(1); \
        } \
        print_success(); \
    }   while (0)

#define ASSERT_FALSE(actual) \
    do { \
        if (actual == true) {\
            std::cout << "[Error]: " << actual << " is true" << std::endl; \
            std::exit(1); \
        } \
        print_success(); \
    }   while (0)

class TestFixture {
    public:
        virtual void    SetUp() = 0;
        virtual void    TearDown() = 0;
        virtual ~TestFixture() {};
};

class TestBureaucrat: public TestFixture {
    public:
        TestBureaucrat() {
            SetUp();
        }
        virtual ~TestBureaucrat() {
            TearDown();
        }
        void    test_default_constructor() {
            ASSERT_EQ(John->getName(), "default");
            ASSERT_EQ(John->getGrade(), 150);
        }
        void    test_overloaded_constructor() {
            ASSERT_EQ(Patrick->getGrade(), 43);
            ASSERT_EQ(Patrick->getName(), "Patrick");
        }
        void    test_copy_constructor() {
            Bureaucrat Pat(*Henry);
            ASSERT_EQ(Pat.getName(), Henry->getName());
            ASSERT_EQ(Pat.getGrade(), Henry->getGrade());
        }
        void    test_assignement_operator() {
            Bureaucrat Pat("Pat", 42);

            Pat = *Patrick;
            ASSERT_EQ(Pat.getName(), "Pat");
            ASSERT_EQ(Pat.getGrade(), Patrick->getGrade());
        }
        void    test_too_high_grade() {
            bool catched(false);
            try {
                Bureaucrat wrong("Wrong", -1);
            } catch (std::exception& e) {
                std::cout << e.what() << std::endl;
                catched = true;
            }
            ASSERT_TRUE(catched);
        }
        void    test_too_low_grade() {
            bool catched(false);
            try {
                Bureaucrat wrong("Wrong", 151);
            } catch (std::exception& e) {
                std::cout << e.what() << std::endl;
                catched = true;
            }
            ASSERT_TRUE(catched);
        }
        void    test_incrementation_out_of_range() {
            bool catched(false);
            try {
                Bureaucrat wrong("Wrong", 42);
                for (size_t index(wrong.getGrade()); index < 152; index++) {
                    wrong.decrementGrade();
                }
            } catch (std::exception& e) {
                std::cout << e.what() << std::endl;
                catched = true;
            }
            ASSERT_TRUE(catched);
        }
        void    test_decrementation_out_of_range() {
            bool catched(false);
            try {
                Bureaucrat wrong("Wrong", 42);
                for (size_t index(wrong.getGrade()); index > 0; index--) {
                    wrong.incrementGrade();
                }
            } catch (std::exception& e) {
                std::cout << e.what() << std::endl;
                catched = true;
            }
            ASSERT_TRUE(catched);
        }
        void    test_print() {
            std::cout << Henry << std::endl;
        }
    private:
        virtual void SetUp() {
            John = new Bureaucrat();
            Patrick = new Bureaucrat("Patrick", 43);
            Henry = new Bureaucrat("Henry", 44);
        }
        virtual void TearDown() {
            delete Henry;
            delete Patrick;
            delete John;

            Henry = NULL;
            Patrick = NULL;
            John = NULL;
        }
        Bureaucrat *Patrick;
        Bureaucrat *Henry;
        Bureaucrat *John;
};

int     main() {
    TestBureaucrat test;
    test.test_default_constructor();
    test.test_overloaded_constructor();
    test.test_copy_constructor();
    test.test_assignement_operator();
    test.test_too_high_grade();
    test.test_too_low_grade();
    test.test_incrementation_out_of_range();
    test.test_decrementation_out_of_range();
    test.test_print();
}