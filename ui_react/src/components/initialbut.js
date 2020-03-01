import React from "react";
import {Button , withStyles, Typography, IconButton } from "@material-ui/core";
import MenuIcon from '@material-ui/icons/Menu'
import PropTypes from 'prop-types';

const useStyles = {
    adas: {
        backgroundColor: "#b2ff59",
        color: "black",
        // maxHeight: "50px",
        height: "50px",
    }
};


function Buts(props){
    const {classes} = props;
    return(
        <div>
            <Button className={classes.adas} variant="contained" color="primary" fullWidth="true" size="large">
            <Typography variant="h4">
                Autopilot is  OFF
            </Typography>
            </Button>
        <Button variant="contained" color="primary" size="large">
            V2X
        </Button>
        </div>

    );
}

Buts.propTypes = {
    classes: PropTypes.object.isRequired,
} ;

export default withStyles(useStyles)(Buts);
