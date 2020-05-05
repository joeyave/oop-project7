//
// Created by avelt on 5/3/2020.
//

#ifndef PROJECT7_TEXTUREHOLDER_H
#define PROJECT7_TEXTUREHOLDER_H

#include <map>
#include <memory>
#include <SFML/Graphics/Texture.hpp>
#include <cassert>

template<typename Identifier>
class TextureHolder {
public:
    TextureHolder<Identifier>() : textureMap() {
    }

    void load(const Identifier identifier, const std::string& fileName) {
        std::unique_ptr<sf::Texture> texture(new sf::Texture());
        assert(texture->loadFromFile(fileName));    //	Load file and check if path is valid.

        insertResource(identifier, std::move(texture));
    }

    sf::Texture& get(const Identifier identifier) const {
        auto foundID = textureMap.find(identifier);
        //	Check if parameter identifier exists within map.
        assert(foundID != textureMap.end());

        return *foundID->second.get();
    }

    int size() {
        return textureMap.size();
    }

private:
    void insertResource(Identifier id, std::unique_ptr<sf::Texture> texture) {
        auto inserted = textureMap.insert(std::make_pair(id, std::move(texture)));
        assert(inserted.second);
    }

    std::map<Identifier, std::unique_ptr<sf::Texture>> textureMap;
};


#endif //PROJECT7_TEXTUREHOLDER_H
