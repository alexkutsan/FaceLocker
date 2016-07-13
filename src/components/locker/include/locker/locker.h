#ifndef LOCKER_H
#define LOCKER_H

/**
 * @brief The Locker class provide possibility
 * to lock workstation
 */
class Locker {
public:
    virtual ~Locker(){}
    /**
     * @brief Lock lock workstation
     */
    virtual void Lock() = 0;
};

#endif // LOCKER_H
