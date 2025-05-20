#pragma once

/**
 * bool testInsertAfterExistingElement()
 * Pārbauda, vai funkcija korekti ievieto elementu pēc pirmā atrastā esošā elementa vidū saistitā sarakstā.
 * Atgriež: true, ja rezultāts sakrīt ar gaidīto
 */
bool testInsertAfterExistingElement();


/**
 * bool testInsertAtEnd()
 * Pārbauda, vai funkcija korekti ievieto elementu pašās beigās saistitā sarakstā.
 * Atgriež: true, ja rezultāts sakrīt ar gaidīto
 */
bool testInsertAtEnd();


/**
 * bool testInsertAfterNonExistingElement()
 * Pārbauda, vai funkcija korekti rīkojas, ja elements pec kura ievietot netiek atrasts saistitā sarakstā.
 * Atgriež: true, ja rezultāts sakrīt ar gaidīto
 */
bool testInsertAfterNonExistingElement();


/**
 * bool testInsertAfterFirstElement()
 * Pārbauda, vai funkcija korekti ievieto jaunu elementu pēc pirmā elementa saistitā sarakstā.
 * Atgriež: true, ja rezultāts sakrīt ar gaidīto
 */
bool testInsertAfterFirstElement();


/**
 * bool testInsertMultipleEqualElement()
 * Pārbauda, vai funkcija ievieto tikai pēc pirmā sastaptā skaitla m, ja skaitlis m sarakstā ir vairākas reizes.
 * Atgriež: true, ja rezultāts sakrīt ar gaidīto
 */
bool testInsertMultipleEqualElement();


/**
 * bool testInsertAfterLastElement()
 * Pārbauda, vai funkcija korekti ievieto jaunu elementu, ja saistitā sarakstā ir tikai viens elements.
 * Atgriež: true, ja rezultāts sakrīt ar gaidīto
 */
bool testInsertAfterOneElement();
