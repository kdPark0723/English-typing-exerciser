#include "Platform.h"

#include "ResourceSystem.h"

Resource * CreateResource(int _size, char * _fileName)
{
    int i, length, mode, lastLength;

    Resource* resource;
    FILE* file_pointer;
    char buffer[INPUT_MAX];
    char ch;

    i = 0;
    mode = 0;
    lastLength = 0;

    resource = (Resource*)malloc(sizeof(Resource));
    resource->size = _size;

    resource->Get = _Resource_Get;

    file_pointer = fopen(_fileName, "a");
    if (file_pointer)
        fclose(file_pointer);
    file_pointer = fopen(_fileName, "r");

    if (file_pointer == NULL)
        return resource;

    while (i <= resource->size && file_pointer)
    {
        fscanf(file_pointer, "%s", buffer);

        length = strlen(buffer);

        if (length > 0)
        {
            if ((ch = fgetc(file_pointer)) == '\n' || ch == 0 || ch == EOF)
            {
                if (mode == 0)
                {
                    char* tmpStr = (char*)malloc(sizeof(char) * (length + 1));

                    strcpy(tmpStr, buffer);
                    resource->buffer[i] = tmpStr;
                }
                else if (mode == 1)
                {
                    lastLength += length;

                    char* tmpStr = (char*)malloc(sizeof(char) * (lastLength + 1));

                    strcpy(tmpStr, resource->buffer[i]);
                    strcat(tmpStr, buffer);

                    free(resource->buffer[i]);

                    resource->buffer[i] = tmpStr;
                }

                ++i;

                mode = 0;
                lastLength = 0;

                if (ch == EOF)
                    break;
            }
            else if (ch == ' ')
            {
                lastLength += length;

                if (mode == 0)
                {
                    char* tmpStr = (char*)malloc(sizeof(char) * (length + 2));

                    strcpy(tmpStr, buffer);

                    tmpStr[length] = ' ';
                    tmpStr[length + 1] = 0;

                    resource->buffer[i] = tmpStr;
                }
                else if (mode == 1)
                {
                    char* tmpStr = (char*)malloc(sizeof(char) * (lastLength + 2));

                    strcpy(tmpStr, resource->buffer[i]);
                    strcat(tmpStr, buffer);

                    buffer[length] = ' ';
                    buffer[length + 1] = 0;

                    free(resource->buffer[i]);

                    resource->buffer[i] = tmpStr;
                }

                mode = 1;
            }
            
        }
        else
            break;
    }

    resource->size = i;

    if (file_pointer)
        fclose(file_pointer);

    return resource;

}

ResourceSystem * CreateResourceSystem(Application * _own)
{
    ResourceSystem* resourceSystem;
  
    resourceSystem = (ResourceSystem*)malloc(sizeof(ResourceSystem));

    resourceSystem->own = _own;
    resourceSystem->resource[WINDOWTYPE_INIT] = CreateResource(0, "WINDOWTYPE_INIT.txt");
    resourceSystem->resource[WINDOWTYPE_SEATPRACTICE] = CreateResource(52, "WINDOWTYPE_SEATPRACTICE.txt");
    resourceSystem->resource[WINDOWTYPE_WORDPRACTICE] = CreateResource(100, "WINDOWTYPE_WORDPRACTICE.txt");
    resourceSystem->resource[WINDOWTYPE_SHORTSENTENCEPRACTICE] = CreateResource(30, "WINDOWTYPE_SHORTSENTENCEPRACTICE.txt");
    resourceSystem->resource[WINDOWTYPE_LONGSENTENCEPRACTICE] = CreateResource(1, "WINDOWTYPE_LONGSENTENCEPRACTICE.txt");
    resourceSystem->Get = _ResourceSystem_Get;

    return resourceSystem;
}

int DestroyResourceSystem(ResourceSystem * _resourceSystem)
{
    DestroyResource(_resourceSystem->resource[WINDOWTYPE_INIT]);
    DestroyResource(_resourceSystem->resource[WINDOWTYPE_SEATPRACTICE]);
    DestroyResource(_resourceSystem->resource[WINDOWTYPE_WORDPRACTICE]);
    DestroyResource(_resourceSystem->resource[WINDOWTYPE_SHORTSENTENCEPRACTICE]);
    DestroyResource(_resourceSystem->resource[WINDOWTYPE_LONGSENTENCEPRACTICE]);

    free(_resourceSystem);

    return 0;
}

int DestroyResource(Resource * _resource)
{
    int i;

    for (i = 0; i < _resource->size; ++i)
        free(_resource->buffer[i]);

    free(_resource);

    return 0;
}

char* _Resource_Get(Resource* _this)
{
    if (_this->size)
        return _this->buffer[rand() % _this->size];
    return NULL;
}
char* _ResourceSystem_Get(ResourceSystem* _this, int _type)
{
    return _this->resource[_type]->Get(_this->resource[_type]);
}
