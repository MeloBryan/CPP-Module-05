/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmelo <bmelo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 21:59:56 by bmelo             #+#    #+#             */
/*   Updated: 2026/11/08 21:14:02 by bmelo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include "AForm.hpp"

#ifndef INTERNDEBUG
#define INTERNDEBUG 0
#endif

class Intern
{
    public :
        Intern();
        ~Intern();
        AForm* makeForm(std::string formName, std::string target);
};

#endif