/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-fr <mjoao-fr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 16:09:49 by mjoao-fr          #+#    #+#             */
/*   Updated: 2026/01/19 16:12:59 by mjoao-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_H
# define MACROS_H

//----------------------------PARSING ERRORS------------------------------------

# define ARGS_ERROR "The program must be run with a something.cub file."
# define WALLS_ERROR "The map must be surrounded by walls (1)."
# define ERROR_IDENTIFIER "Invalid identifier.  \
Expected definitions of NO, SO, WE, EA and F, C first and then the map."
# define CHARS_ERROR "The map contains invalid characters. \
Only 0, 1, N, S, E, W are valid."
# define EMPTY_LINE_ERROR "The map can't contain an empty \
line in the middle."
# define DUPLICATED_COLOR_ERROR "Duplicated definition of a color."
# define DUPLICATED_TEX_ERROR "Duplicated definition of a texture."
# define MISSING_COLOR_ERROR "Colors for floor and ceiling must be defined."
# define INVALID_COLOR "Invalid color code."
# define COLOR_FORMAT_ERROR "Invalid color code.  \
Must be between 0 and 255 only and without spaces in between numbers."
# define RGB_ERROR "Invalid color code. Must be R,G,B format."
# define NO_MAP_ERROR "Nonexisting map."
# define MAP_MEM_ERROR "Error allocating memory for the map."
# define TOO_MANY_PLAYERS_ERROR "You can only have one player in your map."
# define NO_PLAYER_ERROR "You must have one player in your map."
# define XPM_ERROR "Invalid path. Must be something.xpm."
# define NO_TEXTURE_ERROR "Not enough textures defined."
# define TEX_PATH_ERROR "Missing texture's path."
# define TEX_DIRECTORY_ERROR "Texture path is a directory."
# define OPEN_PATH_ERROR "Unable to open a texture's path."
# define IDENTIFIER_ERROR "Invalid identifier."
# define MISS_ID_ERROR "Missing identifier. Expected definitions of NO, SO, \
WE, EA and F, C first and then the map."
# define OPEN_ERROR "Unable to open the file."
# define DIR_ERROR "File cannot be a directory."
# define EMPTY_ERROR "Empty file."

//------------------------------ALGORITHM ERRORS--------------------------------

# define CREATE_SCREEN_ERROR "Failed to create screen image"
# define GET_SCREEN_ERROR "Failed to get screen image addr"
# define LOAD_TEX_ERROR "Failed to load texture"

# define SPEED 0.06
# define ROTATE_SPEED 0.04
# define BOUNDARY 10

#endif