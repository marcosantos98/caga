#include "card.h"

void category_to_cstr(CardCategory category)
{
    switch (category)
    {
    case GENERAL_KNOWLEDGE:
        return "General Knowledge";
    case ENTERTAINMENT_BOOKS:
        return "Entertainment: Books";
    case ENTERTAINMENT_FILM:
        return "Entertainment: Film";
    case ENTERTAINMENT_MUSIC:
        return "Entertainment: Music";
    case ENTERTAINMENT_MUSICALS_AND_THEATRES:
        return "Entertainment: Musicals &AMP Theatres";
    case ENTERTAINMENT_TELEVISION:
        return "Entertainment: Television";
    case ENTERTAINMENT_VIDEO_GAMES:
        return "Entertainment: Video Games";
    case ENTERTAINMENT_BOARD_GAMES:
        return "Entertainment: Board Games";
    case SCIENCE_AND_NATURE:
        return "Science &AMP Nature";
    case SCIENCE_COMPUTERS:
        return "Science: Computers";
    case SCIENCE_MATHEMATICS:
        return "Science: Mathematics";
    case MYTHOLOGY:
        return "Mythology";
    case SPORTS:
        return "Sports";
    case GEOGRAPHY:
        return "Geography";
    case HISTORY:
        return "History";
    case POLITICS:
        return "Politics";
    case ART:
        return "Art";
    case CELEBRITIES:
        return "Celebrities";
    case ANIMALS:
        return "Animals";
    case VEHICLES:
        return "Vehicles";
    case ENTERTAINMENT_COMICS:
        return "Entertainment: Comics";
    case SCIENCE_GADGETS:
        return "Science: Gadgets";
    case ENTERTAINMENT_JAPANESE_ANIME_AND_MANGA:
        return "Entertainment: Japanese Anime &AMP Manga";
    case ENTERTAINMENT_CARTOON_AND_ANIMATIONS:
        return "Entertainment: Cartoon &AMP Animations";
    default:
        printf("Unknown category.\n");
        exit(1);
    }
}