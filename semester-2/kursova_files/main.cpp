#include <iostream>
#include "literature.h"
#include "linkedList.h"
#include "childLiterature.h"
#include "technicalLiterature.h"
#include "poeticLiterature.h"
#include "fantasyLiterature.h"
#include "artisticLiterature.h"
#include "urbanFantasyLiterature.h"
#include "highFantasyLiterature.h"

using namespace std;

int main() {
	LinkedList list;

	list.insert(new ChildLiterature(2015, string("title0"), string("author0"), 8, 12));
	list.insert(new TechnicalLiterature(2015, string("title1"), string("author1"), string("Computer Science"), string("desc")));
	list.insert(new PoeticLiterature(2015, string("title2"), string("author2"), string("Surealism"), string("theme")));
	list.insert(new ArtisticLiterature(2015, string("title3"), string("author3"), string("style"), string("element")));
	list.insert(new FantasyLiterature(2015, string("title4"), string("author4"), string("world setting0"), string("cultivation")));
	list.insert(new UrbanFantasyLiterature(2015, string("title5"), string("author5"), string("world setting1"), string("magic system1"), string("Dark")));
	list.insert(new HighFantasyLiterature(2015, string("title6"), string("author6"), string("world setting2"), string("magic system 2"), string("Elven")));

	list.display();

	return 0;
}