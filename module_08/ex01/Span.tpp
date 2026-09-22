template <typename Iterator>
void       addNumber(Iterator begin, Iterator end) {
    while (begin != end) {
        addNumber(*begin);
        ++begin;
    }
}