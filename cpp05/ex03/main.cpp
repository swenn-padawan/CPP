#include "Intern.hpp"

int main() {
    Intern someRandomIntern;
    AForm* rrf;

    rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    if (rrf)
        delete rrf;

    rrf = someRandomIntern.makeForm("shrubbery creation", "Home");
    if (rrf)
        delete rrf;

    rrf = someRandomIntern.makeForm("presidential pardon", "Ford Prefect");
    if (rrf)
        delete rrf;

    rrf = someRandomIntern.makeForm("unknown form", "Unknown");
    if (rrf)
        delete rrf;

    return 0;
}
