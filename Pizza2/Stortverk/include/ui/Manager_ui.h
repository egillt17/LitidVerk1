#ifndef MANAGER_UI_H
#define MANAGER_UI_H

#include "Validate.h"
#include "Main_ui.h"
#include "TopService.h"
#include "PizzaService.h"
#include <stdlib.h>

class Manager_ui
{
    public:
        /// Main manager UI function
        void managerMainUI();
        /// UI to manage pizza menu items and specials
        void managePizzaUI();
        /// UI to  manage toppings on the pizza
        void manageToppingUI();
        /// UI to manage extra stuff with the pizza, soda or breadsticks
        void manageExtraUI();
        /// UI to manage locations
        void manageLocationUI();
        /// This UI manages the the base pizza ( sauce, crust or size)
        void manageSettingUI();
        /// This function is a menu that chooses either sauce, crust or size
        int crustSauceSize();
        /// This function is a menu that views sales numbers and delivered orders
        void manageSalesUI();

    private:
};

#endif // MANAGER_UI_H
