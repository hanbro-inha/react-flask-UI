import React from "react";
import { AppBar, Toolbar, makeStyles, withStyles, Typography, IconButton } from "@material-ui/core";
import MenuIcon from '@material-ui/icons/Menu'
import PropTypes from 'prop-types';

const useStyles = {
    normal: {
    }
};


function Navbar(props){
    const {classes} = props;
    return(
        <div>
            <AppBar position="static">
                <Toolbar className={classes.normal}>
                    <IconButton color="inherit">
                        <MenuIcon />
                    </IconButton>
                    <Typography variant="h4">
                        ESSYS x INHA V2X 
                    </Typography>
                </Toolbar>
            </AppBar>
        </div>
    );
}

Navbar.propTypes = {
    classes: PropTypes.object.isRequired,
} ;

export default withStyles(useStyles)(Navbar);
