/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmurzi <gmurzi@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 11:14:32 by gmurzi            #+#    #+#             */
/*   Updated: 2026/09/22 11:14:33 by gmurzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <cctype>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <climits>
#include <cfloat>

class ScalarConverter {
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter& other);
        ~ScalarConverter();
        ScalarConverter& operator=(const ScalarConverter& other);
    public:
        static void convert(const std::string& representation);
};
