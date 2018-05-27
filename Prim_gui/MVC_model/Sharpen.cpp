//
// Created by edoardo on 15/05/18.
//

#include "Sharpen.h"

void Sharpen::applyFilter() {
    /* Riepilogo fino a qua: prima di chiamare l'applyFilter, da qualche parte dev'essere stata messa la precedente
     * versione dell'immagine nello stack di undo. Qui si cambiano direttamente i valori dell'immagine. */
    *reds_ = convolute(reds_, false);
    *greens_ = convolute(greens_, false);
    *blues_ = convolute(blues_, false);
    *alphas_ = convolute(alphas_, false);

}