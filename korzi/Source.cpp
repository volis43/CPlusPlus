#include <windows.h>
#include <shellapi.h>

int main()
{
    // Структура, описывающая операцию удаления файлов
    SHFILEOPSTRUCT fileOp;
    ZeroMemory(&fileOp, sizeof(SHFILEOPSTRUCT));
    fileOp.wFunc = FO_DELETE;
    fileOp.pFrom = "C:\\$Recycle.Bin\\*"; // Путь к корзине

    // Выполнение операции удаления
    int result = SHFileOperation(&fileOp);
    if (result != 0)
    {
        // Обработка ошибки
        
    }

    return 0;
}