#include "Widgets/GDTUIUWButtonBase.h"

#include "GDTUICategoryPaletteDefinitions.h"

#if WITH_EDITOR	
const FText UGDTUIUWButtonBase::GetPaletteCategory()
{
    return GDTUICategoryPaletteDefinitions::Default;
}
#endif //WITH_EDITOR