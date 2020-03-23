/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** StartUnifyShowcase
*/

#ifndef StartUnifyShowcase_HPP_
#define StartUnifyShowcase_HPP_

#include "games/include/Start.hpp"

class StartUnifyShowcase : public Start {
    public:
        StartUnifyShowcase();
        ~StartUnifyShowcase();

        void start(IBuilder *builder);
        void update(IBuilder *builder);
        std::string getName() const;
    protected:
    private:

};

#endif /* !StartUnifyShowcase_HPP_ */
