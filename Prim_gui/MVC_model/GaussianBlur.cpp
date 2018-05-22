//
// Created by edoardo on 17/08/17.
//

#include "GaussianBlur.h"

void GaussianBlur::applyFilter() {
    //TODO in pratica deve chiamare 'convolute' tutti e quattro i canali.
    /* Riepilogo fino a qua: prima di chiamare l'applyFilter, da qualche parte dev'essere stata messa la precedente
     * versione dell'immagine nello stack di undo. Qui si cambiano direttamente i valori dell'immagine. */
    *reds_ = convolute(reds_, true);
    *greens_ = convolute(greens_, true);
    *blues_ = convolute(blues_, true);
    *alphas_ = convolute(alphas_, true);

}