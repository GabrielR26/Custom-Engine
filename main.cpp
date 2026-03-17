#include "Engine/Engine.h"

int main()
{
	try
	{
		Engine::Initialization();
	}
	catch (const std::exception& _e)
	{
		LOG_ERROR(_e.what());
	}

    return 0;
}

// Objectif: Créer un moteur de jeu 2D avec gestion des objets
// DONE
// Ajouter un système de ressources pour gérer les textures, sons, etc.
// Ajouter un système de GUI pour gérer les interfaces utilisateur: boutons, image, text
// Ajouter un système de scènes pour gérer les différents écrans du jeu: menu, jeu, pause, etc.
// Ajouter un système de sauvegarde pour permettre de sauvegarder et charger la progression du jeu
// 
// TO DO
// Ajouter un système de caméra pour gérer le point de vue du joueur
