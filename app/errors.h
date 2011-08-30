#ifndef ERRORS_H
#define ERRORS_H

enum Error
{
    EMPTY_USERNAME,
    EMPTY_PASSWORD,
    EMPTY_DB_PATH,
    EMPTY_PASSWORD_CHECK,
    INVALID_USERNAME_PASSWORD,
    UNKNOWN_USER,
    DB_CONNECTION_FAILED,
    DB_CREATION_FAILED,
    INVALID_PATH,
    PASSWORD_UNDER_LIMIT,
    PASSWORD_VERIFICATION_DIFFERENT,
    USER_EXISTS,
    UNDEFINED_ERROR,
    FIELDS_EMPTY,
    PATH_IS_ALREADY_MOOZTIK,
    FAILED_DIR_CREATION,
    NONE
};

#endif // ERRORS_H
