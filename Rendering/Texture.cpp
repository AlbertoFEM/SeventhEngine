/*
 * SeventhEngine
 *
 * Copyright (c) Alberto Fernández
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * @author	Alberto Fernández <albertofem@gmail.com>
 */

#include "Texture.h"
#include "ResourceManager/ResourceManager.h"

namespace Seventh
{
	Texture::Texture(std::string filename)
	{
		mFilename = filename;
	}

	Texture::Texture(std::string packName, std::string textureName)
	{
		mResource = (ResourceTexture*) GResourceManager.getResourceFromPack(packName, "textures", textureName);

		LOG_DEBUG("Creating texture with filename: '%s'", mResource->getFilename().c_str());

		mFilename = mResource->getFilename();
	}

	Texture::~Texture()
	{
		unload();
	}

	bool Texture::load()
	{
		if (mLoaded) {
			return true;
		}

		ILuint imageID;
		ILboolean success;
		ILenum error;

		ilGenImages(1, &imageID); 
		ilBindImage(imageID); 

		LOG_DEBUG("Trying to load texture: '%s'", mFilename.c_str());

		success = ilLoadImage(mFilename.c_str());

		if (success)
		{
			ILinfo ImageInfo;

			iluGetImageInfo(&ImageInfo);

			success = ilConvertImage(IL_RGBA, IL_UNSIGNED_BYTE);

			if (!success)
			{
				error = ilGetError();
				LOG_ERROR("Rendering: Image conversion failed: '%s'", iluErrorString(error));
			}

			mWidth = ilGetInteger(IL_IMAGE_WIDTH);
			mHeight = ilGetInteger(IL_IMAGE_HEIGHT);

			glGenTextures(1, &mTexture);

			glBindTexture(GL_TEXTURE_2D, mTexture);

			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);

			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

			glTexImage2D(
				GL_TEXTURE_2D,
				0,
				ilGetInteger(IL_IMAGE_FORMAT),
				mWidth,
				mHeight,
				0,
				ilGetInteger(IL_IMAGE_FORMAT),
				GL_UNSIGNED_BYTE,
				ilGetData()
			);
		}
		else 
		{
			error = ilGetError();
			LOG_ERROR("Rendering: Image loading failed: '%s'", iluErrorString(error));
		}

		ilDeleteImages(1, &imageID);

		mLoaded = true;
	}

	GLuint Texture::getTextureData()
	{
		return mTexture;
	}

	void Texture::unload()
	{
		// TODO: destroy texture!

		mLoaded = false;
	}

	void Texture::render()
	{
		if (!mLoaded) {
			load();
		}

		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
		glTranslatef(mPosition.x, mPosition.y, 0.0f);

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, mTexture);

		glBegin(GL_QUADS);
			glTexCoord2f(0.0, 0.0); glVertex2f(mPosition.x, mPosition.y);
			glTexCoord2f(0.0, 1.0); glVertex2f(mPosition.x, mPosition.y + mHeight);
			glTexCoord2f(1.0, 1.0); glVertex2f(mPosition.x + mWidth, mPosition.y + mHeight);
			glTexCoord2f(1.0, 0.0); glVertex2f(mPosition.x + mWidth, mPosition.y);
		glEnd();

		glPopMatrix();
	}
}
