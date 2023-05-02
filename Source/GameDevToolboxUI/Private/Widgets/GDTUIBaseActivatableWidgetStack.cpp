#include "Widgets/GDTUIBaseActivatableWidgetStack.h"

#include "GDTUICategoryPaletteDefinitions.h"

#if WITH_EDITOR	
const FText UGDTUIBaseActivatableWidgetStack::GetPaletteCategory()
{
	return GDTUICategoryPaletteDefinitions::Default;
}
#endif //WITH_EDITOR

