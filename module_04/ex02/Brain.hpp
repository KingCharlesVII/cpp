/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmurzi <gmurzi@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 12:41:50 by gmurzi            #+#    #+#             */
/*   Updated: 2026/06/13 12:41:51 by gmurzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

#define MAX_CELLS 100

class Brain {
    public:
        Brain();
        Brain(const Brain& other);
        ~Brain();
        Brain& operator=(const Brain& other);
        const std::string& getIdea(std::size_t index) const;
        void  setIdea(const std::string& idea, size_t index);
    protected:
        std::string ideas[MAX_CELLS] ;
};
