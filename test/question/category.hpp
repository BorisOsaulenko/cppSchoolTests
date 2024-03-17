#include <iostream>
#include <string>

#include <boost/variant.hpp>

#ifndef MATHS_CATEGORIES
#define MATHS_CATEGORIES
enum class MathsCategories
{
    COMPLEX_ANALYSIS,
    ALGEBRA,
    GEOMETRY
};
#endif

#ifndef PHYSICS_CATEGORIES
#define PHYSICS_CATEGORIES
enum class PhysicsCategories
{
    THERMODYNAMICS,
    MECHANICS,
    ELECTROMAGNETISM
};
#endif

#ifndef BIOLOGY_CATEGORIES
#define BIOLOGY_CATEGORIES
enum class BiologyCategories
{
    BOTANY,
    ZOOLOGY,
    MICROBIOLOGY
};
#endif

#ifndef CHEMISTRY_CATEGORIES
#define CHEMISTRY_CATEGORIES
enum class ChemistryCategories
{
    ORGANIC,
    INORGANIC,
    PHYSICAL
};
#endif

#ifndef CATEGORY_VARIANT
#define CATEGORY_VARIANT
typedef boost::variant<MathsCategories, PhysicsCategories, BiologyCategories, ChemistryCategories> categoryVariant;
#endif

#ifndef GENERAL_CATEGORY_NAME
#define GENERAL_CATEGORY_NAME
std::string getGeneralCategoryName(const categoryVariant &category)
{
    if (boost::get<MathsCategories>(&category))
    {
        return "Maths Category";
    }
    else if (boost::get<PhysicsCategories>(&category))
    {
        return "Physics Category";
    }
    else if (boost::get<BiologyCategories>(&category))
    {
        return "Biology Category";
    }
    else if (boost::get<ChemistryCategories>(&category))
    {
        return "Chemistry Category";
    }

    return "Unknown Category";
}
#endif

#ifndef PERCISE_CATEGORY_NAME
#define PERCISE_CATEGORY_NAME
std::string getPerciseCategoryName(const categoryVariant &category)
{
    if (category.which() == 0)
    {
        MathsCategories mathsCategory = boost::get<MathsCategories>(category);
        switch (mathsCategory)
        {
        case MathsCategories::COMPLEX_ANALYSIS:
            return "Complex Analysis";
        case MathsCategories::ALGEBRA:
            return "Algebra";
        case MathsCategories::GEOMETRY:
            return "Geometry";
        default:
            return "Unknown Maths Category";
        }
    }
    else if (category.which() == 1)
    {
        PhysicsCategories physicsCategory = boost::get<PhysicsCategories>(category);
        switch (physicsCategory)
        {
        case PhysicsCategories::THERMODYNAMICS:
            return "Thermodynamics";
        case PhysicsCategories::MECHANICS:
            return "Mechanics";
        case PhysicsCategories::ELECTROMAGNETISM:
            return "Electromagnetism";
        default:
            return "Unknown Physics Category";
        }
    }
    else if (category.which() == 2)
    {
        PhysicsCategories physicsCategory = boost::get<PhysicsCategories>(category);
        switch (physicsCategory)
        {
        case PhysicsCategories::THERMODYNAMICS:
            return "Thermodynamics";
        case PhysicsCategories::MECHANICS:
            return "Mechanics";
        case PhysicsCategories::ELECTROMAGNETISM:
            return "Electromagnetism";
        default:
            return "Unknown Physics Category";
        }
    }
    else if (category.which() == 3)
    {
        ChemistryCategories chemistryCategory = boost::get<ChemistryCategories>(category);
        switch (chemistryCategory)
        {
        case ChemistryCategories::ORGANIC:
            return "Organic";
        case ChemistryCategories::INORGANIC:
            return "Inorganic";
        case ChemistryCategories::PHYSICAL:
            return "Physical";
        default:
            return "Unknown Chemistry Category";
        }
    }

    return "Unknown Category";
}

#endif

#ifndef GET_FULL_CATEGORY_NAME
#define GET_FULL_CATEGORY_NAME

std::string getFullCategoryName(const categoryVariant &category)
{
    return getGeneralCategoryName(category) + ": " + getPerciseCategoryName(category);
}

#endif