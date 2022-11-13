# TrickyKeyringSystem

A small plugin for implementing a flexible keyring system.

## Installation

The plugin can be used in both C++ and Blueprint projects.

### Blueprint projects

**At the moment, the package is compatible only with Unreal Engine 4.**

1. Download [**package file**](https://github.com/TrickyFatCat/TrickyKeyringSystem/releases/tag/v1.0);
2. Unzip the package to the Plugins folder in engine folder, e.g. `C:\Program Files\Epic Games\UE_4.27\Engine\Plugins`;
3. Restart the project;

In this case the plugin can be used for any blueprint project.

### C++ projects

1. Create the Plugins folder in the project directory;
2. Create the TrickyAnimationComponents folder in the Plugins folder;
3. Download the plugin source code into that folder;
4. Rebuild the project;

## Content

The plugin contains:

1. KeyType object;
2. KeyringComponent;
3. KeyringLibrary;

### KeyType object

The object from which key classes must be inherited.

#### Parameters

1. `DestroyOnUse` - toggles if the key must be removed from the keyring after calling the `UseKey` function;
2. `KeyData` - a struct which contains some information for the HUD;
   * `Name` - the name of the key;
   * `Color` - color of the key;

### KeyringComponent

A component which manages keys the player got.

#### Functions

1. `AddKey` - adds a key of a given class to the keyring. Returns true if the key was added;
2. `RemoveKey` - removes a key of a give class from the keyring regardless the value of DestroyOnUse. Returns true if the key was removed;
3. `RemoveAllKeys` - removes all keys in the keyring. Returns true if all keys were removed;
4. `UseKey` - calls the `OnKeyUsed` delegate and removes a key of a given class if DestroyOnUse == true. Returns true if the key was successfully used;
5. `KeyringIsEmpty` - checks if the keyring array is empty;
6. `HasKey` - checks if the keyring has a key of a given class;
7. `GetKeyDataByIndex` - returns key data structure by index of the key in the array;
8. `GetKeyDataByClass` - returns key data structure by given class of the key;

#### Delegates

1. `OnKeyAdded` - called when the key was successfully added to the keyring;
2. `OnKeyRemoved` - called when the key was successfully removed from the keyring;
3. `OnKeyUsed` - called when the key was successfully used;

### KeyringLibrary

A function library with useful functions to work with KeyringComponent.

#### Functions

1. `GetKeyringComponent` - returns KeyringComponent if the given actor has one;
2. `ActorHasKey` - checks if the given actor has key;
3. `AddKey` - adds key to KeyringComponent of the given actor;
4. `RemoveKey` - removes key from KeyringComponent of the given actor;
5. `UseKey` - force the given actor to use the given key class;
6. `GetKeyObject` - returns a key object from KeyringComponent of the given actor;
7. `GetKeyData` - returns key data from KeyringComponent of the given actor;
8. `IsKeyDestroyable` - checks if the given key class is destroyable;
9. `RemoveAllKeys` - removes all keys form KeyringComponent of the given actor;

## Quick setup

1. Add KeyRingComponent to your character;
2. Create key classes you need inherited from KeyType object;
3. Add keys to the keyring or remove them using pickups or custom events;