#include <iostream>
#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>

using namespace std;

bool connection;
char COM[] = "\\\.\\COM5";

class COMPort
{
private:
    HANDLE Port;
    COMSTAT status;
    DWORD errors;
public:

    COMPort(char* portName)
    {
        // - Открытие порта или устройства
        connection = false;
        Port = CreateFileA(portName, GENERIC_WRITE | GENERIC_READ, 0, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL); // Открывает порт или устройство как файл

        // - Проверка на открытие порта устройства
        if (Port == INVALID_HANDLE_VALUE)
        {
            if (GetLastError() != 0)
            {
                cout << "Ошибка №" << GetLastError() << " ";
                cout << "Порт не доступен" << endl;
            }
            else
            {
                cout << "Неизвестная ошибка!" << endl;
            }
        }
        else
        {
            // - Настраиваем порт или устройство в случае успешного открытия
            cout << "Порт открыт! Устанавливаем настройки" << endl;
            DCB DCB_portParameters;
            if (GetCommState(Port, &DCB_portParameters) == 0) // Получаем настройки порта (читает DCB структуру)
            {
                cout << "Получить настройки не удалось или порт не настроен!" << endl;
            }
            else
            {
                // - Заполнение параметры DCB структуры информацией о текущем состоянии устройства
                DCB_portParameters.BaudRate = CBR_9600;
                DCB_portParameters.ByteSize = 8;
                DCB_portParameters.StopBits = ONESTOPBIT;
                DCB_portParameters.Parity = NOPARITY;
                DCB_portParameters.fDtrControl = DTR_CONTROL_ENABLE;
            }

            // - Заносим настройки в порт иил устройство и проверяем их
            if (SetCommState(Port, &DCB_portParameters) == 0) // Функция повторно инициализирует все аппаратные и управляющие настройки, но не очищает очереди вывода или ввода данных (отправляем параметры DCB в порт)
            {
                cout << "Нельзя настроить порт" << endl;
            }
            else
            {
                connection = true;
                PurgeComm(Port, PURGE_RXCLEAR | PURGE_TXCLEAR); // Сбрасывает все символы из буфера вывода - ввода данных порта
                Sleep(2000); // Задержка в выполнении программы
            }
        }
    }

    // - Чтение данных из порта
    int readCOMPort(char* outBuffer, int outBuffer_size)
    {

        DWORD bytesRidden;
        int toRead = 0;

        ClearCommError(Port, &errors, &status);

        if (status.cbInQue > 0) {
            if (status.cbInQue > outBuffer_size)
            {
                toRead = outBuffer_size;
            }
            else toRead = status.cbInQue;
        }

        if (ReadFile(Port, outBuffer, toRead, &bytesRidden, NULL))
        {
            cout << "bytesRidden: " << bytesRidden << endl;
            return bytesRidden;
        }
        
        return 0;
    }

    // - Запись данных в порт
    void writeCOMPort(char* inBuffer, int inBuffer_size)
    {
        DWORD bytesWritten;
        if (WriteFile(Port, inBuffer, inBuffer_size, &bytesWritten, NULL))
        {
            cout << "Отправлено" << endl;
            cout << "bytesWritten: " << bytesWritten << endl;
        }
        else
        {
            cout << "Ошибка!" << endl;
            ClearCommError(Port, &errors, &status);
        }
    }

    ~COMPort()
    {
        connection = false;
        CloseHandle(Port); // Закрытие порта или устройства
    }
};


int main()
{
    setlocale(LC_ALL, "Rus");
    char outBuffer[255]; // - Массив символов нужно указать статическим, чтобы определить его в глобальной памяти. Нужно для того, чтобы не вычищался 
    

    // - Открытие порта
    COMPort MyPort(COM);

    while (connection)
    {
        string data;
        cin >> data;

        char* charArray = new char[data.size() + 1];
        copy(data.begin(), data.end(), charArray);
        charArray[data.size()] = '\n';
        
        /*Как 2-й аргумент влияет на ReadFile?*/MyPort.writeCOMPort(charArray, 200); // если отправить sizeof(charArray) - то не читается в MyPort.readCOMPort. Если отправить sizeof(inBuffer) - читается. 
        MyPort.readCOMPort(outBuffer, sizeof(outBuffer));
        cout << "---->" << outBuffer << endl;

        delete[] charArray;
    }

    return 0;
}

/*Почему читается 11 байт при вводе ON, когда "LED is ON" = 9 байт?*/