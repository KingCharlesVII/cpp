template <typename Iterator>
void       Span::addNumber(Iterator begin, Iterator end) {
    while (begin != end) {
        addNumber(*begin);
        ++begin;
    }
}