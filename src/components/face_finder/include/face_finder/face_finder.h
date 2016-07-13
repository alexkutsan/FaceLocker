#ifndef FACE_FINDER_H
#define FACE_FINDER_H

/**
 * @brief The FaceFinder class provide possibility
 * to find a human faces on the image
 */
class FaceFinder {
public:
    /**
     * @brief Find faces on image
     */
    virtual int FindFaces() = 0;
};

#endif // FACE_FINDER_H
