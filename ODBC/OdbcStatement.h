//
//  OdbcStatement.h
//  OdbcTest1
//
//  Created by Mikael Hakman on 2013-09-03.
//  Copyright (c) 2013 Mikael Hakman. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <sql.h>

@class OdbcConnection;
@class OdbcResultDescriptor;
@class OdbcPrepareDescriptor;

@interface OdbcStatement : NSObject {
    
@protected
    
    SQLHANDLE               hstmt;
    OdbcResultDescriptor  * resultDescriptor;
    OdbcPrepareDescriptor * prepareDescriptor;
}

@property (readonly) SQLHANDLE        hstmt;
@property (readonly) OdbcConnection * connection;
@property (readonly) BOOL             wasNull;

@property (readonly,nonatomic) OdbcResultDescriptor  * resultDescriptor;
@property (readonly,nonatomic) OdbcPrepareDescriptor * prepareDescriptor;

+ (OdbcStatement *) statementWithConnection : newConnection;

- (OdbcStatement *) initWithConnection : newConnection;

- (void) execDirect : (NSString *) sql;

- (BOOL) fetch;

- (void) closeCursor;

- (void) prepare : (NSString *) sql;

- (void) execute;

- (long) getLong : (int) columnNumber;

- (long) getLongByName : (NSString *) columnName;

- (NSString *) getString : (int) columnNumber;

- (NSString *) getStringByName : (NSString *) columnName;

- (double) getDouble : (int) columnNumber;

- (double) getDoubleByName : (NSString *) columnName;

- (NSDate *) getDate : (int) columnNumber;

- (NSDate *) getDateByName : (NSString *) columnName;

- (void) setLong : (int) parameterNumber value : (long) value;

- (void) setString : (int) parameterNumber value : (NSString *) value;

- (void) setDouble : (int) parameterNumber value : (double) value;

- (void) setDate : (int) parameterNumber value : (NSDate *) value;

- (void) setObject : (int) parameterNumber value : (id) value;

- (void) setTime : (int) parameterNumber value : (NSDate *) value;

- (void) setTimestamp : (int) parameterNumber value : (NSDate *) value;

@end
