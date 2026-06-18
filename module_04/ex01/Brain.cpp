/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmurzi <gmurzi@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 12:41:41 by gmurzi            #+#    #+#             */
/*   Updated: 2026/06/13 12:41:43 by gmurzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
    std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain& other) {
    std::cout << "Brain Copy constructor called" << std::endl;
    *this = other;
}

Brain::~Brain() {
    std::cout << "Brain destructor called" << std::endl;
}

Brain& Brain::operator=(const Brain& other) {
    std::cout << "Brain assignement operator called" << std::endl;
    if (this != &other)
        for (std::size_t index = 0; index < MAX_CELLS; index++)
            ideas[index] = std::string(other.getIdea(index));
    return *this;
}

const std::string& Brain::getIdea(std::size_t index) const {
    if (index >= MAX_CELLS) {
        std::cout << "Error while getting an idea: idea index out of range" << std::endl;
       return ideas[0];
    }
    return ideas[index];
}

void  Brain::setIdea(const std::string& idea, size_t index) {
    if (index >= MAX_CELLS) {
        std::cout << "Error while setting an idea: idea index out of range" << std::endl;
        return;
    }
    ideas[index] = idea;
}
