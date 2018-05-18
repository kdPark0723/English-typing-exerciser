#include "Platform.h"

#include "ResourceSystem.h"

Resource * CreateResource(int _size, int _count, char* _fileName)
{
    int i, length, lastLength;

    Resource* resource;
    FILE* file_pointer;

    resource = (Resource*)malloc(sizeof(Resource));

    resource->Get = _Resource_Get;

    if (!_size || !_count)
    {
        resource->count = 0;
        resource->buffer = 0;

        return resource;
    } 

    file_pointer = fopen(_fileName, "ab");
    if (file_pointer)
        fclose(file_pointer);
    file_pointer = fopen(_fileName, "rb");

    if (file_pointer == NULL)
        return resource;

    resource->buffer = (char **)malloc(sizeof(char *) * _count);
    resource->buffer[0] = (char *)malloc(sizeof(char) * _size * _count);

    resource->count = fread(resource->buffer[0], sizeof(unsigned char) * _size, _count, file_pointer);

    if (!resource->count)
    {
        free(resource->buffer[0]);
        free(resource->buffer);
        resource->buffer = 0;

        fclose(file_pointer);

        return resource;
    }

    for (i = 1; i < _count; i++)
        resource->buffer[i] = resource->buffer[i - 1] + sizeof(unsigned char) * _size;


    fclose(file_pointer);

    return resource;

}

ResourceSystem * CreateResourceSystem(Application * _own)
{
    ResourceSystem* resourceSystem;
  
    resourceSystem = (ResourceSystem*)malloc(sizeof(ResourceSystem));

    resourceSystem->own = _own;
    resourceSystem->resource[WINDOWTYPE_INIT] = CreateResource(0, 0, "resource_init.bin");
    resourceSystem->resource[WINDOWTYPE_SEATPRACTICE] = CreateResource(2, 52, "resource_seatpractice.bin");
    resourceSystem->resource[WINDOWTYPE_WORDPRACTICE] = CreateResource(20, 100, "resource_wordpractice.bin");
    resourceSystem->resource[WINDOWTYPE_SHORTSENTENCEPRACTICE] = CreateResource(INPUT_MAX, 30, "resource_shortsentencepractice.bin");
    resourceSystem->resource[WINDOWTYPE_LONGSENTENCEPRACTICE] = CreateResource(INPUT_MAX,1, "resource_longsentencepractice.bin");

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
    if (_resource->buffer && _resource->count)
    {
        free(_resource->buffer[0]);
        free(_resource->buffer);
    }
    free(_resource);

    return 0;
}

char* _Resource_Get(Resource* _this)
{
    if (_this->count)
        return _this->buffer[rand() % _this->count];

    return 0;
}
char* _ResourceSystem_Get(ResourceSystem* _this, int _type)
{
    return _this->resource[_type]->Get(_this->resource[_type]);
}
