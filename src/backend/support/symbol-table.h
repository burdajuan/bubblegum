#ifndef _SYMBOL_TABLE_H_
#define _SYMBOL_TABLE_H_

#include "../../utils/data-types.h"
#include "../semantic-analysis/abstract-syntax-tree.h"
#include "uthash.h"

#define VARNAME_MAX_LENGTH 64

// we know the type bc of the enum, so now we want to know how to read it
typedef union {
    boolean_t boolean;
    int integer;
    float floating;
    char* color;
    char* string;
    char* points;
} ParameterValue;
typedef struct {
    parameter_t type;  // key
    ParameterValue value;

    UT_hash_handle hh;  // make the struct hashable
} ParameterMap;

typedef union {
    AnimationType animationType;
    MediaType mediaType;
    char textType;
    ShapeType shapeType;
    layout_t layoutType;
} VariableType;

typedef struct {
    char id[VARNAME_MAX_LENGTH];  // key
    VariableType type;
    ParameterMap* parameters;

    UT_hash_handle hh;  // make the struct hashable
} SymbolTable;

void stInit();
void stDestroy();

int stAddVariable(char varname[VARNAME_MAX_LENGTH], VariableType type, ParameterMap** parameters);
int stAddParametersToShape(ParameterMap** map, ShapeNode* shapeNode);
int stAddParametersToAnimation(ParameterMap** map, AnimationNode* node);
int stAddParametersToMedia(ParameterMap** map, MediaNode* node);
int stAddParametersToText(ParameterMap** map, TextNode* node);

#endif  // _SYMBOL_TABLE_H_