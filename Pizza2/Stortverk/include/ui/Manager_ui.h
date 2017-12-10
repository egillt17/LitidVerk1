#ifndef MANAGER_UI_H
#define MANAGER_UI_H

#include "Main_ui.h"
#include "TopService.h"
#include <stdlib.h>

class Manager_ui
{
    public:

        void managerMainUI();

        void managePizzaUI();

        void manageToppingUI();

        void manageExtraUI();

        void manageLocationUI();

        void manageSettingUI();

        int crustSauceSize();

    private:
};

#endif // MANAGER_UI_H
